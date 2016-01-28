$NetBSD: patch-crypto_bn_bn__prime.pl,v 1.4 2016/01/28 16:30:43 jperkin Exp $

--- crypto/bn/bn_prime.pl.orig	2016-01-28 13:38:30.000000000 +0000
+++ crypto/bn/bn_prime.pl
@@ -1,6 +1,8 @@
 #!/usr/local/bin/perl
 # bn_prime.pl
 
+use POSIX;
+
 $num=2048;
 $num=$ARGV[0] if ($#ARGV >= 0);
 
@@ -9,7 +11,7 @@ $p=1;
 loop: while ($#primes < $num-1)
 	{
 	$p+=2;
-	$s=int(sqrt($p));
+	$s=floor(sqrt($p));
 
 	for ($i=0; defined($primes[$i]) && $primes[$i]<=$s; $i++)
 		{
