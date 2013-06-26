$NetBSD: patch-src_dar__suite_dar__manager.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/dar_suite/dar_manager.cpp.orig	2013-06-20 19:21:17.000000000 +0000
+++ src/dar_suite/dar_manager.cpp
@@ -78,7 +78,7 @@ using namespace libdar;
 #define MISSING_ARG "Missing argument to -%c"
 #define INVALID_ARG "Invalid argument given to -%c (requires integer)"
 
-enum operation { none_op, create, add, listing, del, chbase, where, options, dar, restore, used, files, stats, move, interactive, check, batch };
+enum operation { none_op, create, add, listing, del, chbase, where, options, dar, restore, used, files, stats, my_move, interactive, check, batch };
 
 static S_I little_main(user_interaction & dialog, S_I argc, char *const argv[], const char **env);
 static bool command_line(user_interaction & dialog,
@@ -183,7 +183,7 @@ S_I little_main(user_interaction & dialo
     case used:
     case files:
     case stats:
-    case move:
+    case my_move:
     case interactive:
     case check:
     case batch:
@@ -386,7 +386,7 @@ static bool command_line(user_interactio
 		case 'm':
 		    if(op != none_op)
 			throw Erange("command_line", tools_printf(gettext(ONLY_ONCE), char(lu)));
-		    op = move;
+		    op = my_move;
 		    if(optarg == NULL)
 			throw Erange("command_line", tools_printf(gettext(MISSING_ARG), char(lu)));
 		    num = tools_str2int(optarg);
@@ -448,7 +448,7 @@ static bool command_line(user_interactio
 		    {
 			try
 			{
-			    deci tmp = string(optarg);
+			    libdar::deci tmp = string(optarg);
 			    date = tmp.computer();
 			}
 			catch(Edeci & e)
@@ -529,7 +529,7 @@ static bool command_line(user_interactio
 	    break;
 	case options:
 	    break;
-	case move:
+	case my_move:
 	    if(rest.size() != 1)
 	    {
 		dialog.warning(gettext("Missing argument to command line, aborting"));
@@ -1068,7 +1068,7 @@ static void op_interactive(user_interact
 		saved = false;
 		break;
 	    case 'm':
-		input = dialog.get_string(gettext("Archive number to move: "), true);
+		input = dialog.get_string(gettext("Archive number to my_move: "), true);
 		num = tools_str2int(input);
 		input = dialog.get_string(gettext("In which position to insert this archive: "), true);
 		num2 = tools_str2int(input);
@@ -1298,7 +1298,7 @@ static void finalize(user_interaction & 
     case where:
     case options:
     case dar:
-    case move:
+    case my_move:
     case batch:
 	if(info_details)
 	    dialog.warning(gettext("Compressing and writing back database to file..."));
@@ -1362,7 +1362,7 @@ static void action(user_interaction & di
     case stats:
 	op_stats(dialog, dat, info_details);
 	break;
-    case move:
+    case my_move:
 	op_move(dialog, dat, num, num2, info_details);
 	break;
     case interactive:
