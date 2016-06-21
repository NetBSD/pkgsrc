$NetBSD: patch-pyhash.py,v 1.1 2016/06/21 18:00:02 joerg Exp $

--- pyhash.py.orig	2014-07-29 06:26:59.000000000 +0000
+++ pyhash.py
@@ -58,9 +58,9 @@ class TestHasher(unittest.TestCase):
 class TestFNV1(TestHasher):
     def testFNV1_32(self):
         self.doTest(hasher_type=fnv1_32,
-                    bytes_hash=3698262380L,
+                    bytes_hash=3698262380,
                     seed_hash=660137056,
-                    unicode_hash=3910690890L)
+                    unicode_hash=3910690890)
 
     def testFNV1a_32(self):
         self.doTest(hasher_type=fnv1a_32,
@@ -70,15 +70,15 @@ class TestFNV1(TestHasher):
 
     def testFNV1_64(self):
         self.doTest(hasher_type=fnv1_64,
-                    bytes_hash=17151984479173897804L,
-                    seed_hash=6349570372626520864L,
-                    unicode_hash=14017453969697934794L)
+                    bytes_hash=17151984479173897804,
+                    seed_hash=6349570372626520864,
+                    unicode_hash=14017453969697934794)
 
     def testFNV1a_64(self):
         self.doTest(hasher_type=fnv1a_64,
-                    bytes_hash=11830222609977404196L,
-                    seed_hash=8858165303110309728L,
-                    unicode_hash=14494269412771327550L)
+                    bytes_hash=11830222609977404196,
+                    seed_hash=8858165303110309728,
+                    unicode_hash=14494269412771327550)
 
 
 class TestMurMurHash(TestHasher):
@@ -86,49 +86,49 @@ class TestMurMurHash(TestHasher):
         self.doTest(hasher_type=murmur1_32,
                     bytes_hash=1706635965,
                     seed_hash=1637637239,
-                    unicode_hash=2296970802L)
+                    unicode_hash=2296970802)
 
     def testMurMurHash1Aligned_32(self):
         self.doTest(hasher_type=murmur1_aligned_32,
                     bytes_hash=1706635965,
                     seed_hash=1637637239,
-                    unicode_hash=2296970802L)
+                    unicode_hash=2296970802)
 
     def testMurMurHash2_32(self):
         self.doTest(hasher_type=murmur2_32,
                     bytes_hash=403862830,
                     seed_hash=1257009171,
-                    unicode_hash=2308212514L)
+                    unicode_hash=2308212514)
 
     def testMurMurHash2a_32(self):
         self.doTest(hasher_type=murmur2a_32,
                     bytes_hash=1026673864,
-                    seed_hash=3640713775L,
-                    unicode_hash=3710634486L)
+                    seed_hash=3640713775,
+                    unicode_hash=3710634486)
 
     def testMurMurHash2Aligned32(self):
         self.doTest(hasher_type=murmur2_aligned_32,
                     bytes_hash=403862830,
                     seed_hash=1257009171,
-                    unicode_hash=2308212514L)
+                    unicode_hash=2308212514)
 
     def testMurMurHash2Neutral32(self):
         self.doTest(hasher_type=murmur2_neutral_32,
                     bytes_hash=403862830,
                     seed_hash=1257009171,
-                    unicode_hash=2308212514L)
+                    unicode_hash=2308212514)
 
     def testMurMurHash2_x64_64a(self):
         self.doTest(hasher_type=murmur2_x64_64a,
-                    bytes_hash=3407684658384555107L,
-                    seed_hash=14278059344916754999L,
-                    unicode_hash=9820020607534352415L)
+                    bytes_hash=3407684658384555107,
+                    seed_hash=14278059344916754999,
+                    unicode_hash=9820020607534352415)
 
     def testMurMurHash2_x86_64b(self):
         self.doTest(hasher_type=murmur2_x86_64b,
-                    bytes_hash=1560774255606158893L,
-                    seed_hash=11567531768634065834L,
-                    unicode_hash=7104676830630207180L)
+                    bytes_hash=1560774255606158893,
+                    seed_hash=11567531768634065834,
+                    unicode_hash=7104676830630207180)
 
     def testMurMurHash3_32(self):
         self.doTest(hasher_type=murmur3_32,
@@ -138,20 +138,20 @@ class TestMurMurHash(TestHasher):
 
     def testMurMurHash3_x86_128(self):
         self.doTest(hasher_type=murmur3_x86_128,
-                    bytes_hash=113049230771270950235709929058346397488L,
-                    seed_hash=201730919445129814667855021331871906456L,
-                    unicode_hash=34467989874860051826961972957664456325L)
+                    bytes_hash=113049230771270950235709929058346397488,
+                    seed_hash=201730919445129814667855021331871906456,
+                    unicode_hash=34467989874860051826961972957664456325)
 
     def testMurMurHash3_x64_128(self):
         self.doTest(hasher_type=murmur3_x64_128,
-                    bytes_hash=204797213367049729698754624420042367389L,
-                    seed_hash=25000065729391260169145522623652811022L,
-                    unicode_hash=301054382688326301269845371608405900524L)
+                    bytes_hash=204797213367049729698754624420042367389,
+                    seed_hash=25000065729391260169145522623652811022,
+                    unicode_hash=301054382688326301269845371608405900524)
 
 class TestLookup3(TestHasher):
     def testLookup3(self):
         self.doTest(hasher_type=lookup3,
-                    bytes_hash=3188463954L,
+                    bytes_hash=3188463954,
                     seed_hash=478901866,
                     unicode_hash=1380664715)
 
@@ -167,17 +167,17 @@ class TestSuperFastHash(TestHasher):
 class TestCityHash(TestHasher):
     def testCityHash64(self):
         self.doTest(hasher_type=city_64,
-                    bytes_hash=17703940110308125106L,
-                    seed_hash=8806864191580960558L,
-                    unicode_hash=7557950076747784205L)
+                    bytes_hash=17703940110308125106,
+                    seed_hash=8806864191580960558,
+                    unicode_hash=7557950076747784205)
 
         self.assertFalse(hasattr(city_64, 'has_sse4_2'))
 
     def testCityHash128(self):
         self.doTest(hasher_type=city_128,
-                    bytes_hash=195179989828428219998331619914059544201L,
-                    seed_hash=206755929755292977387372217469167977636L,
-                    unicode_hash=211596129097514838244042408160146499227L)
+                    bytes_hash=195179989828428219998331619914059544201,
+                    seed_hash=206755929755292977387372217469167977636,
+                    unicode_hash=211596129097514838244042408160146499227)
 
         self.assertTrue(city_128.has_sse4_2, "support SSE 4.2")
 
@@ -185,21 +185,21 @@ class TestCityHash(TestHasher):
 class TestSpookyHash(TestHasher):
     def testSpookyHash32(self):
         self.doTest(hasher_type=spooky_32,
-                    bytes_hash=1882037601L,
-                    seed_hash=1324274298L,
-                    unicode_hash=2977967976L)
+                    bytes_hash=1882037601,
+                    seed_hash=1324274298,
+                    unicode_hash=2977967976)
 
     def testSpookyHash64(self):
         self.doTest(hasher_type=spooky_64,
-                    bytes_hash=10130480990056717665L,
-                    seed_hash=1598355329892273278L,
-                    unicode_hash=4093159241144086376L)
+                    bytes_hash=10130480990056717665,
+                    seed_hash=1598355329892273278,
+                    unicode_hash=4093159241144086376)
 
     def testSpookyHash128(self):
         self.doTest(hasher_type=spooky_128,
-                    bytes_hash=241061513486538422840128476001680072033L,
-                    seed_hash=315901747311404831226315334184550174199L,
-                    unicode_hash=207554373952009549684886824908954283880L)
+                    bytes_hash=241061513486538422840128476001680072033,
+                    seed_hash=315901747311404831226315334184550174199,
+                    unicode_hash=207554373952009549684886824908954283880)
 
 if __name__ == '__main__':
     if "-v" in sys.argv:
