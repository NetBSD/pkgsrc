$NetBSD: patch-grid.c,v 1.1 2026/03/19 14:51:40 nia Exp $

Modern GCC no longer likes implicit int.

--- grid.c.orig	1995-04-25 07:04:38.000000000 +0000
+++ grid.c
@@ -296,7 +296,7 @@ void draw_chords()
 	}
 
 /*--------------------------------------------------------------------------------*/
-clean_chordtab()
+void clean_chordtab()
 	{
 	struct chord_struct *ct_ptr, *ct_next; 
 	ct_ptr= so_chordtab;
@@ -311,7 +311,7 @@ clean_chordtab()
 	}
 
 /*--------------------------------------------------------------------------------*/
-clean_known_chords()
+void clean_known_chords()
 	{
 	struct kcs *kc_ptr, **prev_kc_ptr;
 
@@ -334,6 +334,7 @@ clean_known_chords()
 		}
 	}
 /*--------------------------------------------------------------------------------*/
+void
 count_known_chords() /* Debugging routines only */
 	{
 	struct kcs *kc_ptr;
@@ -359,6 +360,7 @@ count_known_chords() /* Debugging routin
 	fprintf (stderr, "%d builtin, %d in chordrc, %d in song\n", int_count, rc_count, song_count);  
 	}
 /*--------------------------------------------------------------------------------*/
+void
 learn_chord(chord, s1, s2, s3, s4, s5, s6, displ, origin, difficult)
 char 	*chord;
 int	displ;
