$NetBSD: patch-src_util_date.c,v 1.3 2024/04/05 17:03:59 wiz Exp $

Ensure proper value range to ctype ops (toupper, isalnum, ...).

--- src/util/date.c.orig	2023-04-12 12:05:25.000000000 +0000
+++ src/util/date.c
@@ -129,9 +129,9 @@ static size_t match_string(const char *d
 	for (i = 0; *date; date++, str++, i++) {
 		if (*date == *str)
 			continue;
-		if (toupper(*date) == toupper(*str))
+		if (toupper((unsigned char)*date) == toupper((unsigned char)*str))
 			continue;
-		if (!isalnum(*date))
+		if (!isalnum((unsigned char)*date))
 			break;
 		return 0;
 	}
@@ -143,7 +143,7 @@ static int skip_alpha(const char *date)
 	int i = 0;
 	do {
 		i++;
-	} while (isalpha(date[i]));
+	} while (isalpha((unsigned char)date[i]));
 	return i;
 }
 
@@ -251,7 +251,7 @@ static size_t match_multi_number(unsigne
 
 	num2 = strtol(end+1, &end, 10);
 	num3 = -1;
-	if (*end == c && isdigit(end[1]))
+	if (*end == c && isdigit((unsigned char)end[1]))
 		num3 = strtol(end+1, &end, 10);
 
 	/* Time? Date? */
@@ -349,7 +349,7 @@ static size_t match_digit(const char *da
 	case '.':
 	case '/':
 	case '-':
-		if (isdigit(end[1])) {
+		if (isdigit((unsigned char)end[1])) {
 			size_t match = match_multi_number(num, *end, date, end, tm);
 			if (match)
 				return match;
@@ -364,7 +364,7 @@ static size_t match_digit(const char *da
 	n = 0;
 	do {
 		n++;
-	} while (isdigit(date[n]));
+	} while (isdigit((unsigned char)date[n]));
 
 	/* Four-digit year or a timezone? */
 	if (n == 4) {
@@ -518,7 +518,7 @@ static int parse_date_basic(const char *
 			match = match_alpha(date, &tm, offset);
 		else if (isdigit(c))
 			match = match_digit(date, &tm, offset, &tm_gmt);
-		else if ((c == '-' || c == '+') && isdigit(date[1]))
+		else if ((c == '-' || c == '+') && isdigit((unsigned char)date[1]))
 			match = match_tz(date, offset);
 
 		if (!match) {
@@ -682,7 +682,7 @@ static const char *approxidate_alpha(con
 	const char *end = date;
 	int i;
 
-	while (isalpha(*++end))
+	while (isalpha((unsigned char)*++end))
 		/* scan to non-alpha */;
 
 	for (i = 0; i < 12; i++) {
@@ -783,7 +783,7 @@ static const char *approxidate_digit(con
 	case '.':
 	case '/':
 	case '-':
-		if (isdigit(end[1])) {
+		if (isdigit((unsigned char)end[1])) {
 			size_t match = match_multi_number(number, *end, date, end, tm);
 			if (match)
 				return date + match;
