$NetBSD: patch-src_smaSHeM.cpp,v 1.1 2013/12/06 21:26:05 joerg Exp $

--- src/smaSHeM.cpp.orig	2013-11-29 12:09:30.000000000 +0000
+++ src/smaSHeM.cpp
@@ -22,7 +22,7 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 #include "smaSHeM.h"
 
-void usage(char *commandname) {
+void usage(const char *commandname) {
 	if (commandname != (char *) NULL) {
 		fprintf(stderr, "usage: %s -v | -i <shmemid> -l <shmemlength> <-@ <patchoffset> -s <patchstring> | -d [-p | -c | -P | -j -x <xstart> -X <endx> -y <starty> -Y <yend>]>\n", commandname);
 	} else {
@@ -31,7 +31,7 @@ void usage(char *commandname) {
 	exit(EXIT_FAILURE);
 }
 
-void error(char *commandname, char *errorstring) {
+void error(const char *commandname, const char *errorstring) {
 	if (errno) {
 		if (errorstring != (char *) NULL) {
 			perror(errorstring);
@@ -164,7 +164,7 @@ int main(int argc, char **argv) {
 						if ((shmembuffer = (void *) shmat(shmemid, (void *) NULL, SHM_RND)) != (void *) -1) {
 							if (patchstring != (char *) NULL) {
 								for (patchcounter = 0; patchcounter < strlen(patchstring); patchcounter ++) {
-									*((char *) (shmembuffer + patchoffset + patchcounter)) = *(patchstring + patchcounter);
+									*((char *)shmembuffer + patchoffset + patchcounter) = *(patchstring + patchcounter);
 								}
 							}
 							shmdt(shmembuffer);
@@ -181,32 +181,32 @@ int main(int argc, char **argv) {
 								if (jpegflag != TRUE) {
 									for (displaycounter = 0; displaycounter < shmemlength; displaycounter ++) {
 										if (perlflag == TRUE) {
-											printf("\\x%02x", (unsigned char) *((char *) (shmembuffer + displaycounter)));
+											printf("\\x%02x", (unsigned char) *((char *)shmembuffer + displaycounter));
 										} else {
 											if (cflag == TRUE) {
-												printf("0x%02x", (unsigned char) *((char *) (shmembuffer + displaycounter)));
+												printf("0x%02x", (unsigned char) *((char *)shmembuffer + displaycounter));
 												if ((displaycounter + 1) < shmemlength) {
 													printf(",");
 												}
 											} else {
 												if (prettyflag == TRUE) {
 													if ((displaycounter % PRETTYLINELENGTH) == 0) {
-														printf("0x%08x\t", shmembuffer + displaycounter);
+														printf("0x%08x\t", (char *)shmembuffer + displaycounter);
 													}
 													if ((displaycounter % PRETTYLINELENGTH) > 0) {
 														printf(" ");
 													}
-													if (isalnum((unsigned char) *((char *) (shmembuffer + displaycounter)))) {
-														prettybuffer[displaycounter % PRETTYLINELENGTH] = (unsigned char) *((char *) (shmembuffer + displaycounter));
+													if (isalnum((unsigned char) *((char *)shmembuffer + displaycounter))) {
+														prettybuffer[displaycounter % PRETTYLINELENGTH] = (unsigned char) *((char *)shmembuffer + displaycounter);
 													} else {
 														prettybuffer[displaycounter % PRETTYLINELENGTH] = (unsigned char) '.';
 													}
-													printf("%02x", (unsigned char) *((char *) (shmembuffer + displaycounter)));
+													printf("%02x", (unsigned char) *((char *)shmembuffer + displaycounter));
 													if ((displaycounter % PRETTYLINELENGTH) == (PRETTYLINELENGTH - 1)) {
 														printf("\t%s\n", prettybuffer);
 													}
 												} else {
-													printf("%c", (unsigned char) *((char *) (shmembuffer + displaycounter)));
+													printf("%c", (unsigned char) *((char *)shmembuffer + displaycounter));
 												}
 											}
 										}
