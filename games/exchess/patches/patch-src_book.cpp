$NetBSD: patch-src_book.cpp,v 1.1 2014/09/11 16:59:16 jperkin Exp $

Avoid 'move' conflict.

--- src/book.cpp.orig	2014-08-17 11:03:08.000000000 +0000
+++ src/book.cpp
@@ -44,7 +44,7 @@ void build_book(position ipos)
   char instring[100], line[100];     // strings from input files
   char outbook[100], resp;
   position temp_pos;                 // temporary position
-  move bmove;                        // book move under consideration
+  my_move bmove;                     // book move under consideration
   unsigned __int64 pcode;            // hash code for position
   int i = -1, j = 0, p,q;            // loop variables
   int r, s;                    
@@ -314,7 +314,7 @@ void build_book(position ipos)
 //--------------------------------------------------------
 // Function to find a position in the book
 //--------------------------------------------------------
-int find_record(position p, move m, int file_size, book_rec *book_record, fstream *book_f, int file_pos)
+int find_record(position p, my_move m, int file_size, book_rec *book_record, fstream *book_f, int file_pos)
 {
   int jump = int(file_size/2);
   unsigned __int64 pcode = ZERO;
@@ -384,12 +384,12 @@ int find_record(position p, move m, int
 // becomes a candidate move.  Information is stored to
 // facilitate easy learning during the game.
 //--------------------------------------------------------
-move opening_book(h_code hash_code, position p, game_rec *gr)
+my_move opening_book(h_code hash_code, position p, game_rec *gr)
 {
   int file_size, mflag = 0, j;
   int candidates = 0, total_score = 0;
   move_list list;
-  move nomove; nomove.t = 0;
+  my_move nomove; nomove.t = 0;
   char book_file[100];          // file name for the book
   book_rec book_record;         // record of move considered
   int file_pos;                 // file position of record
@@ -680,7 +680,7 @@ int edit_book(h_code hash_code, position
   if(outflag == 1) cout << "\n";
 
   /* Edit mode for individual moves */
-  move edit_move;
+  my_move edit_move;
   while(1) {
     cout << "\nEnter a move to be edited/investigated (0 = quit): ";
     cin >> mstring; if(mstring[0] == '0') break;
