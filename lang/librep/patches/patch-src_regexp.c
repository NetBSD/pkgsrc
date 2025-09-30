$NetBSD: patch-src_regexp.c,v 1.1 2025/09/30 14:29:17 gutteridge Exp $

Use ctype.h correctly.

--- src/regexp.c.orig	2017-08-25 19:59:05.000000000 +0000
+++ src/regexp.c
@@ -711,8 +711,8 @@ rep_regexec2(rep_regexp *prog, char *str
 	s = string;
 	if(regnocase)
 	{
-	    mat[0] = tolower(UCHARAT(prog->regmust));
-	    mat[1] = toupper(UCHARAT(prog->regmust));
+	    mat[0] = tolower((unsigned char)UCHARAT(prog->regmust));
+	    mat[1] = toupper((unsigned char)UCHARAT(prog->regmust));
 	    while ((s = strpbrk(s, mat)) != NULL)
 	    {
 		if(strncasecmp(s, prog->regmust, prog->regmlen) == 0)
@@ -748,8 +748,8 @@ rep_regexec2(rep_regexp *prog, char *str
 	/* We know what char it must start with. */
 	if(regnocase)
 	{
-	    mat[0] = tolower(prog->regstart);
-	    mat[1] = toupper(prog->regstart);
+	    mat[0] = tolower((unsigned char)prog->regstart);
+	    mat[1] = toupper((unsigned char)prog->regstart);
 	    while((s = strpbrk(s, mat)) != NULL)
 	    {
 		if(regtry(prog, s))
@@ -892,7 +892,7 @@ regmatch(char *prog)
 		if(regnocase)
 		{
 		    /* Inline the first character, for speed. */
-		    if(toupper(UCHARAT(opnd)) != toupper(UCHARAT(reginput)))
+		    if(toupper((unsigned char)UCHARAT(opnd)) != toupper((unsigned char)UCHARAT(reginput)))
 			return (0);
 		    len = strlen(opnd);
 		    if(len > 1 && strncasecmp(opnd, reginput, len) != 0)
@@ -1011,14 +1011,14 @@ regmatch(char *prog)
 		if (OP(next) == EXACTLY)
 		    nextch = UCHARAT(OPERAND(next));
 		if(regnocase)
-		    nextch = toupper(nextch);
+		    nextch = toupper((unsigned char)nextch);
 		min = (OP(scan) == STAR) ? 0 : 1;
 		save = reginput;
 		no = regrepeat(OPERAND(scan));
 		while (no >= min) {
 		    /* If it could work, try it. */
 		    if (nextch == '\0'
-			|| (regnocase ? toupper(UCHARAT(reginput))
+			|| (regnocase ? toupper((unsigned char)UCHARAT(reginput))
 			    : *reginput) == nextch)
 			if (nested_regmatch(next))
 			    return (1);
@@ -1044,7 +1044,7 @@ regmatch(char *prog)
 		if (OP(next) == EXACTLY)
 		    nextch = UCHARAT(OPERAND(next));
 		if(regnocase)
-		    nextch = toupper(nextch);
+		    nextch = toupper((unsigned char)nextch);
 		no = (OP(scan) == NGSTAR) ? 0 : 1;
 		save = reginput;
 		max = regrepeat(OPERAND(scan));
@@ -1052,7 +1052,7 @@ regmatch(char *prog)
 		    reginput = save + no;
 		    /* If it could work, try it. */
 		    if (nextch == '\0'
-			|| (regnocase ? toupper(UCHARAT(reginput))
+			|| (regnocase ? toupper((unsigned char)UCHARAT(reginput))
 			    : *reginput) == nextch)
 			if (nested_regmatch(next))
 			    return (1);
@@ -1063,49 +1063,49 @@ regmatch(char *prog)
 	    }
 	    break;
 	case WORD:
-	    if (*reginput != '_' && !isalnum (UCHARAT(reginput)))
+	    if (*reginput != '_' && !isalnum ((unsigned char)UCHARAT(reginput)))
 		return 0;
 	    reginput++;
 	    break;
 	case NWORD:
-	    if (*reginput == '_' || isalnum (UCHARAT(reginput)))
+	    if (*reginput == '_' || isalnum ((unsigned char)UCHARAT(reginput)))
 		return 0;
 	    reginput++;
 	    break;
 	case WSPC:
-	    if (!isspace (UCHARAT(reginput)))
+	    if (!isspace ((unsigned char)UCHARAT(reginput)))
 		return 0;
 	    reginput++;
 	    break;
 	case NWSPC:
-	    if (isspace (UCHARAT(reginput)))
+	    if (isspace ((unsigned char)UCHARAT(reginput)))
 		return 0;
 	    reginput++;
 	    break;
 	case DIGI:
-	    if (!isdigit (UCHARAT(reginput)))
+	    if (!isdigit ((unsigned char)UCHARAT(reginput)))
 		return 0;
 	    reginput++;
 	    break;
 	case NDIGI:
-	    if (isdigit (UCHARAT(reginput)))
+	    if (isdigit ((unsigned char)UCHARAT(reginput)))
 		return 0;
 	    reginput++;
 	    break;
 	case WEDGE:
 	    if (reginput == regbol || *reginput == '\0'
-		|| ((reginput[-1] == '_' || isalnum (UCHARAT(reginput - 1)))
-		    && (*reginput != '_' && !isalnum (UCHARAT(reginput))))
-		|| ((reginput[-1] != '_' && !isalnum (UCHARAT(reginput - 1)))
-		    && (*reginput == '_' || isalnum (UCHARAT(reginput)))))
+		|| ((reginput[-1] == '_' || isalnum ((unsigned char)UCHARAT(reginput - 1)))
+		    && (*reginput != '_' && !isalnum ((unsigned char)UCHARAT(reginput))))
+		|| ((reginput[-1] != '_' && !isalnum ((unsigned char)UCHARAT(reginput - 1)))
+		    && (*reginput == '_' || isalnum ((unsigned char)UCHARAT(reginput)))))
 		break;
 	    return 0;
 	case NWEDGE:
 	    if (!(reginput == regbol || *reginput == '\0'
-		  || ((reginput[-1] == '_' || isalnum (UCHARAT(reginput - 1)))
-		      && (*reginput != '_' && !isalnum (UCHARAT(reginput))))
-		  || ((reginput[-1] != '_' && !isalnum (UCHARAT(reginput - 1)))
-		      && (*reginput == '_' || isalnum (UCHARAT(reginput))))))
+		  || ((reginput[-1] == '_' || isalnum ((unsigned char)UCHARAT(reginput - 1)))
+		      && (*reginput != '_' && !isalnum ((unsigned char)UCHARAT(reginput))))
+		  || ((reginput[-1] != '_' && !isalnum ((unsigned char)UCHARAT(reginput - 1)))
+		      && (*reginput == '_' || isalnum ((unsigned char)UCHARAT(reginput))))))
 		break;
 	    return 0;
 	case END:
@@ -1147,7 +1147,7 @@ regrepeat(char *p)
     case EXACTLY:
 	if(regnocase)
 	{
-	    while(toupper(UCHARAT(opnd)) == toupper(UCHARAT(scan))) {
+	    while(toupper((unsigned char)UCHARAT(opnd)) == toupper((unsigned char)UCHARAT(scan))) {
 		scan++;
 	    }
 	}
@@ -1169,32 +1169,32 @@ regrepeat(char *p)
 	}
 	break;
     case WORD:
-	while (*scan != '\0' && (*scan == '_' || isalnum (UCHARAT(scan)))) {
+	while (*scan != '\0' && (*scan == '_' || isalnum ((unsigned char)UCHARAT(scan)))) {
 	    scan++;
 	}
 	break;
     case NWORD:
-	while (*scan != '\0' && (*scan != '_' && !isalnum (UCHARAT(scan)))) {
+	while (*scan != '\0' && (*scan != '_' && !isalnum ((unsigned char)UCHARAT(scan)))) {
 	    scan++;
 	}
 	break;
     case WSPC:
-	while (*scan != '\0' && isspace (UCHARAT(scan))) {
+	while (*scan != '\0' && isspace ((unsigned char)UCHARAT(scan))) {
 	    scan++;
 	}
 	break;
     case NWSPC:
-	while (*scan != '\0' && !isspace (UCHARAT(scan))) {
+	while (*scan != '\0' && !isspace ((unsigned char)UCHARAT(scan))) {
 	    scan++;
 	}
 	break;
     case DIGI:
-	while (*scan != '\0' && isdigit (UCHARAT(scan))) {
+	while (*scan != '\0' && isdigit ((unsigned char)UCHARAT(scan))) {
 	    scan++;
 	}
 	break;
     case NDIGI:
-	while (*scan != '\0' && !isdigit (UCHARAT(scan))) {
+	while (*scan != '\0' && !isdigit ((unsigned char)UCHARAT(scan))) {
 	    scan++;
 	}
 	break;
