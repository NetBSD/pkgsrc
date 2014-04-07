$NetBSD: patch-ezPyCrypto.py,v 1.1 2014/04/07 12:36:38 obache Exp $

* IDEA and RC5 had been removed from pycrypto 2.1.0alpha1

--- ezPyCrypto.py.orig	2003-07-23 23:03:43.000000000 +0000
+++ ezPyCrypto.py
@@ -25,7 +25,7 @@ Features:
  - Export private keys with a different (or no) passphrase
  - Sensible defaults - no need to specify a zillion options (or any options
    at all) unless you  want to
- - Algorithms include RSA, ElGamal, DSA, ARC2, Blowfish, CAST, DES3, IDEA and RC5
+ - Algorithms include RSA, ElGamal, DSA, ARC2, Blowfish, CAST and DES3
    (default RSA and Blowfish)
  - Choose your own public and session key sizes (or accept defaults)
 
@@ -69,7 +69,7 @@ import Crypto
 from Crypto.PublicKey import ElGamal, DSA, RSA
 from Crypto.Util.randpool import RandomPool
 from Crypto.Util.number import getPrime
-from Crypto.Cipher import ARC2, Blowfish, CAST, DES3, IDEA, RC5
+from Crypto.Cipher import ARC2, Blowfish, CAST, DES3
 from Crypto.Hash import MD5
 
 #@-body
@@ -168,13 +168,13 @@ class key:
     _algosPub1 = {ElGamal:'ElGamal', RSA:'RSA'}
     
     _algosSes = { "ARC2":ARC2, "Blowfish":Blowfish, "CAST":CAST,
-                  "DES3":DES3, "IDEA":IDEA, "RC5":RC5}
-    _algosSes1 = {'ARC2':0, 'Blowfish':1, 'CAST':2, 'DES3':3, 'IDEA':4, 'RC5':5}
+                  "DES3":DES3}
+    _algosSes1 = {'ARC2':0, 'Blowfish':1, 'CAST':2, 'DES3':3}
     
-    _algosSes2 = [ARC2, Blowfish, CAST, DES3, IDEA, RC5]
+    _algosSes2 = [ARC2, Blowfish, CAST, DES3]
     
     _algosSes3 = {ARC2:'ARC2', Blowfish:'Blowfish', CAST:'CAST',
-                  DES3:'DES3', IDEA:'IDEA', RC5:'RC5'}
+                  DES3:'DES3'}
     
     # Generate IV for passphrase encryption
     _passIV = "w8Z4(51fKH#p{!29Q05HWcb@K 6(1qdyv{9|4=+gvji$chw!9$38^2cyGK#;}'@DHx%3)q_skvh4#0*="
@@ -201,7 +201,7 @@ class key:
          1. If new keys are desired:
              - key size in bits (int), default 512 - advise at least 1536
              - algoPub - either 'RSA' or 'ElGamal' (default 'RSA')
-             - algoSess - one of 'ARC2', 'Blowfish', 'CAST', 'DES3', 'IDEA', 'RC5',
+             - algoSess - one of 'ARC2', 'Blowfish', 'CAST', 'DES3',
                (default 'Blowfish')
          2. If importing an existing key or keypair:
              - keyobj (string) - result of a prior exportKey() call
@@ -231,7 +231,7 @@ class key:
             algoS = self._algosSes.get(algoSess, None)
             if algoS == None:
                 # Whoops - don't know that session algorithm
-                raise Exception("AlgoSess must be one of AES/ARC2/Blowfish/CAST/DES/DES3/IDEA/RC5")
+                raise Exception("AlgoSess must be one of AES/ARC2/Blowfish/CAST/DES/DES3")
             self.algoSes = algoS
             self.algoSname = algoSess
     
