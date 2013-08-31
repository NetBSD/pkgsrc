$NetBSD: patch-xa__x11.c,v 1.1 2013/08/31 14:52:50 joerg Exp $

--- xa_x11.c.orig	2013-08-31 14:15:35.000000000 +0000
+++ xa_x11.c
@@ -1464,7 +1464,7 @@ void xanim_events()
     XChangeProperty(theDisp, mainW, window_atom, XA_STRING, 8,
 		    PropModeReplace, (unsigned char *)command, 1);
     if (xa_window_prepare_flag == xaFALSE)
-      xanim_expose(theWG, event, NULL, 0);
+      xanim_expose(theWG, &event, NULL, 0);
     while (1)
     {
       XtAppNextEvent(theContext, &event);
@@ -1504,50 +1504,50 @@ void xanim_events()
 	    break;
 	  case ' ':
 	    if (xa_anim_status == XA_UNSTARTED) 
-	      xanim_expose(theWG, event, NULL, 0);
-	    else xanim_toggle_action(theWG, event, NULL, 0);
+	      xanim_expose(theWG, &event, NULL, 0);
+	    else xanim_toggle_action(theWG, &event, NULL, 0);
 	    break;
 	  case ',':
-	    xanim_step_prev_action(theWG, event, NULL, 0);
+	    xanim_step_prev_action(theWG, &event, NULL, 0);
 	    break;
 	  case '.':
-	    xanim_step_next_action(theWG, event, NULL, 0);
+	    xanim_step_next_action(theWG, &event, NULL, 0);
 	    break;
 	  case 'm':
-	    xanim_step_prev_int_action(theWG, event, NULL, 0);
+	    xanim_step_prev_int_action(theWG, &event, NULL, 0);
 	    break;
 	  case '/':
-	    xanim_step_next_int_action(theWG, event, NULL, 0);
+	    xanim_step_next_int_action(theWG, &event, NULL, 0);
 	    break;
 	  case '-':
-	    xanim_faster_action(theWG, event, NULL, 0);
+	    xanim_faster_action(theWG, &event, NULL, 0);
 	    break;
 	  case '=':
-	    xanim_slower_action(theWG, event, NULL, 0);
+	    xanim_slower_action(theWG, &event, NULL, 0);
 	    break;
 	  case '0':
-	    xanim_speed_reset_action(theWG, event, NULL, 0);
+	    xanim_speed_reset_action(theWG, &event, NULL, 0);
 	    break;
 	  case '1':
-	    xanim_dec_audio_5(theWG, event, NULL, 0);
+	    xanim_dec_audio_5(theWG, &event, NULL, 0);
 	    break;
 	  case '2':
-	    xanim_dec_audio_1(theWG, event, NULL, 0);
+	    xanim_dec_audio_1(theWG, &event, NULL, 0);
 	    break;
 	  case '3':
-	    xanim_inc_audio_1(theWG, event, NULL, 0);
+	    xanim_inc_audio_1(theWG, &event, NULL, 0);
 	    break;
 	  case '4':
-	    xanim_inc_audio_5(theWG, event, NULL, 0);
+	    xanim_inc_audio_5(theWG, &event, NULL, 0);
 	    break;
 	  case 's':
-	    xanim_mute_audio(theWG, event, NULL, 0);
+	    xanim_mute_audio(theWG, &event, NULL, 0);
 	    break;
 	  case '8':
-	    xanim_speaker_tog(theWG, event, NULL, 0);
+	    xanim_speaker_tog(theWG, &event, NULL, 0);
 	    break;
 	  case '9':
-	    xanim_headphone_tog(theWG, event, NULL, 0);
+	    xanim_headphone_tog(theWG, &event, NULL, 0);
 	    break;
 	  case 'v':
 	    vaudiof->volume = atoi( &command[1] );
@@ -1559,7 +1559,7 @@ void xanim_events()
 	    XA_AUDIO_SET_VOLUME(vaudiof->volume);
 	    break;
 	  case 'z':
-	    xanim_realize_remote(theWG, event, NULL, 0);
+	    xanim_realize_remote(theWG, &event, NULL, 0);
 	    break;
 	  case 'e':
 	    x11_expose_flag = xaTRUE;
