$NetBSD: patch-lib_crypto_CipherContext.cpp,v 1.1 2020/04/12 19:45:51 joerg Exp $

OpenSSL 1.1 compat.

--- lib/crypto/CipherContext.cpp.orig	2020-04-12 15:12:39.687647444 +0000
+++ lib/crypto/CipherContext.cpp
@@ -94,6 +94,7 @@ CipherContext::CipherContext()
 	  mpDescription(0)
 #endif
 {
+	ctx = EVP_CIPHER_CTX_new();
 }
 
 // --------------------------------------------------------------------------
@@ -109,7 +110,7 @@ CipherContext::~CipherContext()
 	if(mInitialised)
 	{
 		// Clean up
-		EVP_CIPHER_CTX_cleanup(&ctx);
+		EVP_CIPHER_CTX_free(ctx);
 		mInitialised = false;
 	}
 #ifdef HAVE_OLD_SSL
@@ -144,15 +145,15 @@ void CipherContext::Init(CipherContext::
 	
 	// Initialise the cipher
 #ifndef HAVE_OLD_SSL
-	EVP_CIPHER_CTX_init(&ctx); // no error return code, even though the docs says it does
+	EVP_CIPHER_CTX_init(ctx); // no error return code, even though the docs says it does
 
-	if(EVP_CipherInit_ex(&ctx, rDescription.GetCipher(), NULL, NULL, NULL, Function) != 1)
+	if(EVP_CipherInit_ex(ctx, rDescription.GetCipher(), NULL, NULL, NULL, Function) != 1)
 #else
 	// Store function for later
 	mFunction = Function;
 
 	// Use old version of init call
-	if(EVP_CipherInit(&ctx, rDescription.GetCipher(), NULL, NULL, Function) != 1)
+	if(EVP_CipherInit(ctx, rDescription.GetCipher(), NULL, NULL, Function) != 1)
 #endif
 	{
 		THROW_EXCEPTION(CipherException, EVPInitFailure)
@@ -162,19 +163,19 @@ void CipherContext::Init(CipherContext::
 	{
 #ifndef HAVE_OLD_SSL
 		// Let the description set up everything else
-		rDescription.SetupParameters(&ctx);
+		rDescription.SetupParameters(ctx);
 #else
 		// With the old version, a copy needs to be taken first.
 		mpDescription = rDescription.Clone();
 		// Mark it as not a leak, otherwise static cipher contexts
 		// cause spurious memory leaks to be reported
 		MEMLEAKFINDER_NOT_A_LEAK(mpDescription);
-		mpDescription->SetupParameters(&ctx);
+		mpDescription->SetupParameters(ctx);
 #endif
 	}
 	catch(...)
 	{
-		EVP_CIPHER_CTX_cleanup(&ctx);
+		EVP_CIPHER_CTX_cleanup(ctx);
 		throw;
 	}
 
@@ -195,7 +196,7 @@ void CipherContext::Reset()
 	if(mInitialised)
 	{
 		// Clean up
-		EVP_CIPHER_CTX_cleanup(&ctx);
+		EVP_CIPHER_CTX_cleanup(ctx);
 		mInitialised = false;
 	}
 #ifdef HAVE_OLD_SSL
@@ -232,7 +233,7 @@ void CipherContext::Begin()
 	}
 
 	// Initialise the cipher context again
-	if(EVP_CipherInit(&ctx, NULL, NULL, NULL, -1) != 1)
+	if(EVP_CipherInit(ctx, NULL, NULL, NULL, -1) != 1)
 	{
 		THROW_EXCEPTION(CipherException, EVPInitFailure)
 	}
@@ -278,14 +279,14 @@ int CipherContext::Transform(void *pOutB
 	}
 	
 	// Check output buffer size
-	if(OutLength < (InLength + EVP_CIPHER_CTX_block_size(&ctx)))
+	if(OutLength < (InLength + EVP_CIPHER_CTX_block_size(ctx)))
 	{
 		THROW_EXCEPTION(CipherException, OutputBufferTooSmall);
 	}
 	
 	// Do the transform
 	int outLength = OutLength;
-	if(EVP_CipherUpdate(&ctx, (unsigned char*)pOutBuffer, &outLength, (unsigned char*)pInBuffer, InLength) != 1)
+	if(EVP_CipherUpdate(ctx, (unsigned char*)pOutBuffer, &outLength, (unsigned char*)pInBuffer, InLength) != 1)
 	{
 		THROW_EXCEPTION(CipherException, EVPUpdateFailure)
 	}
@@ -325,7 +326,7 @@ int CipherContext::Final(void *pOutBuffe
 	}
 
 	// Check output buffer size
-	if(OutLength < (2 * EVP_CIPHER_CTX_block_size(&ctx)))
+	if(OutLength < (2 * EVP_CIPHER_CTX_block_size(ctx)))
 	{
 		THROW_EXCEPTION(CipherException, OutputBufferTooSmall);
 	}
@@ -333,7 +334,7 @@ int CipherContext::Final(void *pOutBuffe
 	// Do the transform
 	int outLength = OutLength;
 #ifndef HAVE_OLD_SSL
-	if(EVP_CipherFinal_ex(&ctx, (unsigned char*)pOutBuffer, &outLength) != 1)
+	if(EVP_CipherFinal_ex(ctx, (unsigned char*)pOutBuffer, &outLength) != 1)
 	{
 		THROW_EXCEPTION(CipherException, EVPFinalFailure)
 	}
@@ -362,11 +363,11 @@ void CipherContext::OldOpenSSLFinal(unsi
 	// Old version needs to use a different form, and then set up the cipher again for next time around
 	int outLength = rOutLengthOut;
 	// Have to emulate padding off...
-	int blockSize = EVP_CIPHER_CTX_block_size(&ctx);
+	int blockSize = EVP_CIPHER_CTX_block_size(ctx);
 	if(mPaddingOn)
 	{
 		// Just use normal final call
-		if(EVP_CipherFinal(&ctx, Buffer, &outLength) != 1)
+		if(EVP_CipherFinal(ctx, Buffer, &outLength) != 1)
 		{
 			THROW_EXCEPTION(CipherException, EVPFinalFailure)
 		}
@@ -379,13 +380,13 @@ void CipherContext::OldOpenSSLFinal(unsi
 		{
 			// NASTY -- fiddling around with internals like this is bad.
 			// But only way to get this working on old versions of OpenSSL.
-			if(!EVP_EncryptUpdate(&ctx,Buffer,&outLength,ctx.buf,0)
+			if(!EVP_EncryptUpdate(ctx,Buffer,&outLength,ctx.buf,0)
 				|| outLength != blockSize)
 			{
 				THROW_EXCEPTION(CipherException, EVPFinalFailure)
 			}
 			// Clean up
-			EVP_CIPHER_CTX_cleanup(&ctx);
+			EVP_CIPHER_CTX_cleanup(ctx);
 		}
 		else
 		{
@@ -398,7 +399,7 @@ void CipherContext::OldOpenSSLFinal(unsi
 			// padding, and remove it.
 			char temp[1024];
 			outLength = sizeof(temp);
-			if(EVP_CipherFinal(&ctx, Buffer, &outLength) != 1)
+			if(EVP_CipherFinal(ctx, Buffer, &outLength) != 1)
 			{
 				THROW_EXCEPTION(CipherException, EVPFinalFailure)
 			}
@@ -413,11 +414,11 @@ void CipherContext::OldOpenSSLFinal(unsi
 		}
 	}
 	// Reinitialise the cipher for the next time around
-	if(EVP_CipherInit(&ctx, mpDescription->GetCipher(), NULL, NULL, mFunction) != 1)
+	if(EVP_CipherInit(ctx, mpDescription->GetCipher(), NULL, NULL, mFunction) != 1)
 	{
 		THROW_EXCEPTION(CipherException, EVPInitFailure)
 	}
-	mpDescription->SetupParameters(&ctx);
+	mpDescription->SetupParameters(ctx);
 
 	// Update length for caller
 	rOutLengthOut = outLength;
@@ -442,7 +443,7 @@ int CipherContext::InSizeForOutBufferSiz
 
 	// Strictly speaking, the *2 is unnecessary. However... 
 	// Final() is paranoid, and requires two input blocks of space to work.
-	return OutLength - (EVP_CIPHER_CTX_block_size(&ctx) * 2);
+	return OutLength - (EVP_CIPHER_CTX_block_size(ctx) * 2);
 }
 
 // --------------------------------------------------------------------------
@@ -463,7 +464,7 @@ int CipherContext::MaxOutSizeForInBuffer
 
 	// Final() is paranoid, and requires two input blocks of space to work, and so we need to add
 	// three blocks on to be absolutely sure.
-	return InLength + (EVP_CIPHER_CTX_block_size(&ctx) * 3);
+	return InLength + (EVP_CIPHER_CTX_block_size(ctx) * 3);
 }
 
 
@@ -490,7 +491,7 @@ int CipherContext::TransformBlock(void *
 	}
 
 	// Check output buffer size
-	if(OutLength < (InLength + EVP_CIPHER_CTX_block_size(&ctx)))
+	if(OutLength < (InLength + EVP_CIPHER_CTX_block_size(ctx)))
 	{
 		// Check if padding is off, in which case the buffer can be smaller
 		if(!mPaddingOn && OutLength <= InLength)
@@ -504,7 +505,7 @@ int CipherContext::TransformBlock(void *
 	}
 	
 	// Initialise the cipher context again
-	if(EVP_CipherInit(&ctx, NULL, NULL, NULL, -1) != 1)
+	if(EVP_CipherInit(ctx, NULL, NULL, NULL, -1) != 1)
 	{
 		THROW_EXCEPTION(CipherException, EVPInitFailure)
 	}
@@ -515,14 +516,14 @@ int CipherContext::TransformBlock(void *
 	{
 		// Update
 		outLength = OutLength;
-		if(EVP_CipherUpdate(&ctx, (unsigned char*)pOutBuffer, &outLength, (unsigned char*)pInBuffer, InLength) != 1)
+		if(EVP_CipherUpdate(ctx, (unsigned char*)pOutBuffer, &outLength, (unsigned char*)pInBuffer, InLength) != 1)
 		{
 			THROW_EXCEPTION(CipherException, EVPUpdateFailure)
 		}
 		// Finalise
 		int outLength2 = OutLength - outLength;
 #ifndef HAVE_OLD_SSL
-		if(EVP_CipherFinal_ex(&ctx, ((unsigned char*)pOutBuffer) + outLength, &outLength2) != 1)
+		if(EVP_CipherFinal_ex(ctx, ((unsigned char*)pOutBuffer) + outLength, &outLength2) != 1)
 		{
 			THROW_EXCEPTION(CipherException, EVPFinalFailure)
 		}
@@ -536,7 +537,7 @@ int CipherContext::TransformBlock(void *
 		// Finalise the context, so definately ready for the next caller
 		int outs = OutLength;
 #ifndef HAVE_OLD_SSL
-		EVP_CipherFinal_ex(&ctx, (unsigned char*)pOutBuffer, &outs);
+		EVP_CipherFinal_ex(ctx, (unsigned char*)pOutBuffer, &outs);
 #else
 		OldOpenSSLFinal((unsigned char*)pOutBuffer, outs);
 #endif
@@ -562,7 +563,7 @@ int CipherContext::GetIVLength()
 		THROW_EXCEPTION(CipherException, NotInitialised)
 	}
 	
-	return EVP_CIPHER_CTX_iv_length(&ctx);
+	return EVP_CIPHER_CTX_iv_length(ctx);
 }
 
 
@@ -589,7 +590,7 @@ void CipherContext::SetIV(const void *pI
 	}
 
 	// Set IV
-	if(EVP_CipherInit(&ctx, NULL, NULL, (unsigned char *)pIV, -1) != 1)
+	if(EVP_CipherInit(ctx, NULL, NULL, (unsigned char *)pIV, -1) != 1)
 	{
 		THROW_EXCEPTION(CipherException, EVPInitFailure)
 	}
@@ -628,7 +629,7 @@ const void *CipherContext::SetRandomIV(i
 	}
 
 	// Get length of IV
-	unsigned int ivLen = EVP_CIPHER_CTX_iv_length(&ctx);
+	unsigned int ivLen = EVP_CIPHER_CTX_iv_length(ctx);
 	if(ivLen > sizeof(mGeneratedIV))
 	{
 		THROW_EXCEPTION(CipherException, IVSizeImplementationLimitExceeded)
@@ -638,7 +639,7 @@ const void *CipherContext::SetRandomIV(i
 	Random::Generate(mGeneratedIV, ivLen);
 
 	// Set IV
-	if(EVP_CipherInit(&ctx, NULL, NULL, mGeneratedIV, -1) != 1)
+	if(EVP_CipherInit(ctx, NULL, NULL, mGeneratedIV, -1) != 1)
 	{
 		THROW_EXCEPTION(CipherException, EVPInitFailure)
 	}	
@@ -668,7 +669,7 @@ const void *CipherContext::SetRandomIV(i
 void CipherContext::UsePadding(bool Padding)
 {
 #ifndef HAVE_OLD_SSL
-	if(EVP_CIPHER_CTX_set_padding(&ctx, Padding) != 1)
+	if(EVP_CIPHER_CTX_set_padding(ctx, Padding) != 1)
 	{
 		THROW_EXCEPTION(CipherException, EVPSetPaddingFailure)
 	}
