$NetBSD: patch-src_audio_SDL__wave.c,v 1.1 2019/07/21 11:14:38 nia Exp $

Various CVE fixes from upstream's hg:

CVE-2019-7572: Fix a buffer overread in IMA_ADPCM_nibble
12800:e52413f52586
CVE-2019-7572: Fix a buffer overwrite in IMA_ADPCM_decode
12818:a8afedbcaea0
CVE-2019-7573, CVE-2019-7576: Fix buffer overreads in InitMS_ADPCM
12819:fcbecae42795
CVE-2019-7574: Fix a buffer overread in IMA_ADPCM_decode
12815:a6e3d2f5183e
CVE-2019-7575: Fix a buffer overwrite in MS_ADPCM_decode
12821:a936f9bd3e38
CVE-2019-7577: Fix a buffer overread in MS_ADPCM_nibble and MS_ADPCM_decode
12817:faf9abbcfb5f
CVE-2019-7577: Fix a buffer overread in MS_ADPCM_decode
12816:416136310b88
CVE-2019-7578: Fix a buffer overread in InitIMA_ADPCM
12801:388987dff7bf

--- src/audio/SDL_wave.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/audio/SDL_wave.c
@@ -44,12 +44,13 @@ static struct MS_ADPCM_decoder {
 	struct MS_ADPCM_decodestate state[2];
 } MS_ADPCM_state;
 
-static int InitMS_ADPCM(WaveFMT *format)
+static int InitMS_ADPCM(WaveFMT *format, int length)
 {
-	Uint8 *rogue_feel;
+	Uint8 *rogue_feel, *rogue_feel_end;
 	int i;
 
 	/* Set the rogue pointer to the MS_ADPCM specific data */
+	if (length < sizeof(*format)) goto too_short;
 	MS_ADPCM_state.wavefmt.encoding = SDL_SwapLE16(format->encoding);
 	MS_ADPCM_state.wavefmt.channels = SDL_SwapLE16(format->channels);
 	MS_ADPCM_state.wavefmt.frequency = SDL_SwapLE32(format->frequency);
@@ -58,9 +59,11 @@ static int InitMS_ADPCM(WaveFMT *format)
 	MS_ADPCM_state.wavefmt.bitspersample =
 					 SDL_SwapLE16(format->bitspersample);
 	rogue_feel = (Uint8 *)format+sizeof(*format);
+	rogue_feel_end = (Uint8 *)format + length;
 	if ( sizeof(*format) == 16 ) {
 		rogue_feel += sizeof(Uint16);
 	}
+	if (rogue_feel + 4 > rogue_feel_end) goto too_short;
 	MS_ADPCM_state.wSamplesPerBlock = ((rogue_feel[1]<<8)|rogue_feel[0]);
 	rogue_feel += sizeof(Uint16);
 	MS_ADPCM_state.wNumCoef = ((rogue_feel[1]<<8)|rogue_feel[0]);
@@ -70,12 +73,16 @@ static int InitMS_ADPCM(WaveFMT *format)
 		return(-1);
 	}
 	for ( i=0; i<MS_ADPCM_state.wNumCoef; ++i ) {
+		if (rogue_feel + 4 > rogue_feel_end) goto too_short;
 		MS_ADPCM_state.aCoeff[i][0] = ((rogue_feel[1]<<8)|rogue_feel[0]);
 		rogue_feel += sizeof(Uint16);
 		MS_ADPCM_state.aCoeff[i][1] = ((rogue_feel[1]<<8)|rogue_feel[0]);
 		rogue_feel += sizeof(Uint16);
 	}
 	return(0);
+too_short:
+	SDL_SetError("Unexpected length of a chunk with a MS ADPCM format");
+	return(-1);
 }
 
 static Sint32 MS_ADPCM_nibble(struct MS_ADPCM_decodestate *state,
@@ -115,7 +122,7 @@ static Sint32 MS_ADPCM_nibble(struct MS_
 static int MS_ADPCM_decode(Uint8 **audio_buf, Uint32 *audio_len)
 {
 	struct MS_ADPCM_decodestate *state[2];
-	Uint8 *freeable, *encoded, *decoded;
+	Uint8 *freeable, *encoded, *encoded_end, *decoded, *decoded_end;
 	Sint32 encoded_len, samplesleft;
 	Sint8 nybble, stereo;
 	Sint16 *coeff[2];
@@ -124,6 +131,7 @@ static int MS_ADPCM_decode(Uint8 **audio
 	/* Allocate the proper sized output buffer */
 	encoded_len = *audio_len;
 	encoded = *audio_buf;
+	encoded_end = encoded + encoded_len;
 	freeable = *audio_buf;
 	*audio_len = (encoded_len/MS_ADPCM_state.wavefmt.blockalign) * 
 				MS_ADPCM_state.wSamplesPerBlock*
@@ -134,6 +142,7 @@ static int MS_ADPCM_decode(Uint8 **audio
 		return(-1);
 	}
 	decoded = *audio_buf;
+	decoded_end = decoded + *audio_len;
 
 	/* Get ready... Go! */
 	stereo = (MS_ADPCM_state.wavefmt.channels == 2);
@@ -141,10 +150,14 @@ static int MS_ADPCM_decode(Uint8 **audio
 	state[1] = &MS_ADPCM_state.state[stereo];
 	while ( encoded_len >= MS_ADPCM_state.wavefmt.blockalign ) {
 		/* Grab the initial information for this block */
+		if (encoded + 7 + (stereo ? 7 : 0) > encoded_end) goto invalid_size;
 		state[0]->hPredictor = *encoded++;
 		if ( stereo ) {
 			state[1]->hPredictor = *encoded++;
 		}
+		if (state[0]->hPredictor >= 7 || state[1]->hPredictor >= 7) {
+			goto invalid_predictor;
+		}
 		state[0]->iDelta = ((encoded[1]<<8)|encoded[0]);
 		encoded += sizeof(Sint16);
 		if ( stereo ) {
@@ -167,6 +180,7 @@ static int MS_ADPCM_decode(Uint8 **audio
 		coeff[1] = MS_ADPCM_state.aCoeff[state[1]->hPredictor];
 
 		/* Store the two initial samples we start with */
+		if (decoded + 4 + (stereo ? 4 : 0) > decoded_end) goto invalid_size;
 		decoded[0] = state[0]->iSamp2&0xFF;
 		decoded[1] = state[0]->iSamp2>>8;
 		decoded += 2;
@@ -188,6 +202,9 @@ static int MS_ADPCM_decode(Uint8 **audio
 		samplesleft = (MS_ADPCM_state.wSamplesPerBlock-2)*
 					MS_ADPCM_state.wavefmt.channels;
 		while ( samplesleft > 0 ) {
+			if (encoded + 1 > encoded_end) goto invalid_size;
+			if (decoded + 4 > decoded_end) goto invalid_size;
+
 			nybble = (*encoded)>>4;
 			new_sample = MS_ADPCM_nibble(state[0],nybble,coeff[0]);
 			decoded[0] = new_sample&0xFF;
@@ -209,6 +226,14 @@ static int MS_ADPCM_decode(Uint8 **audio
 	}
 	SDL_free(freeable);
 	return(0);
+invalid_size:
+	SDL_SetError("Unexpected chunk length for a MS ADPCM decoder");
+	SDL_free(freeable);
+	return(-1);
+invalid_predictor:
+	SDL_SetError("Invalid predictor value for a MS ADPCM decoder");
+	SDL_free(freeable);
+	return(-1);
 }
 
 struct IMA_ADPCM_decodestate {
@@ -222,11 +247,12 @@ static struct IMA_ADPCM_decoder {
 	struct IMA_ADPCM_decodestate state[2];
 } IMA_ADPCM_state;
 
-static int InitIMA_ADPCM(WaveFMT *format)
+static int InitIMA_ADPCM(WaveFMT *format, int length)
 {
-	Uint8 *rogue_feel;
+	Uint8 *rogue_feel, *rogue_feel_end;
 
 	/* Set the rogue pointer to the IMA_ADPCM specific data */
+	if (length < sizeof(*format)) goto too_short;
 	IMA_ADPCM_state.wavefmt.encoding = SDL_SwapLE16(format->encoding);
 	IMA_ADPCM_state.wavefmt.channels = SDL_SwapLE16(format->channels);
 	IMA_ADPCM_state.wavefmt.frequency = SDL_SwapLE32(format->frequency);
@@ -235,11 +261,16 @@ static int InitIMA_ADPCM(WaveFMT *format
 	IMA_ADPCM_state.wavefmt.bitspersample =
 					 SDL_SwapLE16(format->bitspersample);
 	rogue_feel = (Uint8 *)format+sizeof(*format);
+	rogue_feel_end = (Uint8 *)format + length;
 	if ( sizeof(*format) == 16 ) {
 		rogue_feel += sizeof(Uint16);
 	}
+	if (rogue_feel + 2 > rogue_feel_end) goto too_short;
 	IMA_ADPCM_state.wSamplesPerBlock = ((rogue_feel[1]<<8)|rogue_feel[0]);
 	return(0);
+too_short:
+	SDL_SetError("Unexpected length of a chunk with an IMA ADPCM format");
+	return(-1);
 }
 
 static Sint32 IMA_ADPCM_nibble(struct IMA_ADPCM_decodestate *state,Uint8 nybble)
@@ -264,6 +295,14 @@ static Sint32 IMA_ADPCM_nibble(struct IM
 	};
 	Sint32 delta, step;
 
+	/* Clamp index value. The inital value can be invalid. */
+	if ( state->index > 88 ) {
+		state->index = 88;
+	} else
+	if ( state->index < 0 ) {
+		state->index = 0;
+	}
+
 	/* Compute difference and new sample value */
 	step = step_table[state->index];
 	delta = step >> 3;
@@ -275,12 +314,6 @@ static Sint32 IMA_ADPCM_nibble(struct IM
 
 	/* Update index value */
 	state->index += index_table[nybble];
-	if ( state->index > 88 ) {
-		state->index = 88;
-	} else
-	if ( state->index < 0 ) {
-		state->index = 0;
-	}
 
 	/* Clamp output sample */
 	if ( state->sample > max_audioval ) {
@@ -323,7 +356,7 @@ static void Fill_IMA_ADPCM_block(Uint8 *
 static int IMA_ADPCM_decode(Uint8 **audio_buf, Uint32 *audio_len)
 {
 	struct IMA_ADPCM_decodestate *state;
-	Uint8 *freeable, *encoded, *decoded;
+	Uint8 *freeable, *encoded, *encoded_end, *decoded, *decoded_end;
 	Sint32 encoded_len, samplesleft;
 	unsigned int c, channels;
 
@@ -339,6 +372,7 @@ static int IMA_ADPCM_decode(Uint8 **audi
 	/* Allocate the proper sized output buffer */
 	encoded_len = *audio_len;
 	encoded = *audio_buf;
+	encoded_end = encoded + encoded_len;
 	freeable = *audio_buf;
 	*audio_len = (encoded_len/IMA_ADPCM_state.wavefmt.blockalign) * 
 				IMA_ADPCM_state.wSamplesPerBlock*
@@ -349,11 +383,13 @@ static int IMA_ADPCM_decode(Uint8 **audi
 		return(-1);
 	}
 	decoded = *audio_buf;
+	decoded_end = decoded + *audio_len;
 
 	/* Get ready... Go! */
 	while ( encoded_len >= IMA_ADPCM_state.wavefmt.blockalign ) {
 		/* Grab the initial information for this block */
 		for ( c=0; c<channels; ++c ) {
+			if (encoded + 4 > encoded_end) goto invalid_size;
 			/* Fill the state information for this block */
 			state[c].sample = ((encoded[1]<<8)|encoded[0]);
 			encoded += 2;
@@ -367,6 +403,7 @@ static int IMA_ADPCM_decode(Uint8 **audi
 			}
 
 			/* Store the initial sample we start with */
+			if (decoded + 2 > decoded_end) goto invalid_size;
 			decoded[0] = (Uint8)(state[c].sample&0xFF);
 			decoded[1] = (Uint8)(state[c].sample>>8);
 			decoded += 2;
@@ -376,6 +413,9 @@ static int IMA_ADPCM_decode(Uint8 **audi
 		samplesleft = (IMA_ADPCM_state.wSamplesPerBlock-1)*channels;
 		while ( samplesleft > 0 ) {
 			for ( c=0; c<channels; ++c ) {
+				if (encoded + 4 > encoded_end) goto invalid_size;
+				if (decoded + 4 * 4 * channels > decoded_end)
+					goto invalid_size;
 				Fill_IMA_ADPCM_block(decoded, encoded,
 						c, channels, &state[c]);
 				encoded += 4;
@@ -387,6 +427,10 @@ static int IMA_ADPCM_decode(Uint8 **audi
 	}
 	SDL_free(freeable);
 	return(0);
+invalid_size:
+	SDL_SetError("Unexpected chunk length for an IMA ADPCM decoder");
+	SDL_free(freeable);
+	return(-1);
 }
 
 SDL_AudioSpec * SDL_LoadWAV_RW (SDL_RWops *src, int freesrc,
@@ -461,7 +505,7 @@ SDL_AudioSpec * SDL_LoadWAV_RW (SDL_RWop
 			break;
 		case MS_ADPCM_CODE:
 			/* Try to understand this */
-			if ( InitMS_ADPCM(format) < 0 ) {
+			if ( InitMS_ADPCM(format, lenread) < 0 ) {
 				was_error = 1;
 				goto done;
 			}
@@ -469,7 +513,7 @@ SDL_AudioSpec * SDL_LoadWAV_RW (SDL_RWop
 			break;
 		case IMA_ADPCM_CODE:
 			/* Try to understand this */
-			if ( InitIMA_ADPCM(format) < 0 ) {
+			if ( InitIMA_ADPCM(format, lenread) < 0 ) {
 				was_error = 1;
 				goto done;
 			}
