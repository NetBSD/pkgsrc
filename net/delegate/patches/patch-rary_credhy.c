$NetBSD: patch-rary_credhy.c,v 1.1 2022/09/18 22:46:25 he Exp $

Fix build by spreading some "unsigned"ness.

--- ./rary/credhy.c.orig	2008-11-14 01:12:53.000000000 +0000
+++ ./rary/credhy.c
@@ -103,10 +103,10 @@ static int DH_Px;
  * 2^255+1351 ... a prime number in 256 bits
  * http://www.utm.edu/research/primes/lists/2small/200bit.html
  */
-static int Pt[] = {
+static unsigned int Pt[] = {
  103078511
 };
-static int P0[] = {
+static unsigned int P0[] = {
 0x80000000,0x00000000,0x00000000,0x00000000,
 0x00000000,0x00000000,0x00000000,0x00000547
 };
@@ -115,7 +115,7 @@ static int P0[] = {
  * From RFC2409(IKE), RFC2539(DNSsec)
  * 2^768 - 2^704 - 1 + 2^64 * { [2^638 pi] + 149686 }
  */
-static int P1[] = {
+static unsigned int P1[] = {
  0xFFFFFFFF,0xFFFFFFFF,0xC90FDAA2,0x2168C234,
  0xC4C6628B,0x80DC1CD1,0x29024E08,0x8A67CC74,
  0x020BBEA6,0x3B139B22,0x514A0879,0x8E3404DD,
@@ -128,7 +128,7 @@ static int P1[] = {
  * From RFC2409, RFC2539
  * 2^1024 - 2^960 - 1 + 2^64 * { [2-894 pi] + 129093 }
  */ 
-static int P2[32] = {
+static unsigned int P2[32] = {
  0xFFFFFFFF,0xFFFFFFFF,0xC90FDAA2,0x2168C234,
  0xC4C6628B,0x80DC1CD1,0x29024E08,0x8A67CC74,
  0x020BBEA6,0x3B139B22,0x514A0879,0x8E3404DD,
@@ -142,7 +142,7 @@ static int P2[32] = {
 /*
  * From RFC3526
  */
-static int P3[] ={
+static unsigned int P3[] ={
  0xFFFFFFFF,0xFFFFFFFF,0xC90FDAA2,0x2168C234,
  0xC4C6628B,0x80DC1CD1,0x29024E08,0x8A67CC74,
  0x020BBEA6,0x3B139B22,0x514A0879,0x8E3404DD,
@@ -159,7 +159,7 @@ static int P3[] ={
 
 static struct {
 	int	 p_size;
-	int	*p_int;
+	unsigned int	*p_int;
 } PX[] = {
 	{ sizeof(P0),	P0 },
 	{ sizeof(P1),	P1 },
@@ -169,7 +169,7 @@ static struct {
 };
 void DH_init(int grp){
 	int i,k,s;
-	int *p;
+	unsigned int *p;
 
 	if( DH_G[LSI] == 2 )
 		return;
