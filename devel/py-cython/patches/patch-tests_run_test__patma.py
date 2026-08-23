$NetBSD: patch-tests_run_test__patma.py,v 1.1 2026/08/23 08:03:49 wiz Exp $

Avoid construct only allowed by Python 3.15 for now.

--- tests/run/test_patma.py.orig	2026-08-23 07:58:25.174800123 +0000
+++ tests/run/test_patma.py
@@ -2933,7 +2933,7 @@ class TestPatma(unittest.TestCase):
     def test_patma_256(self):
         x = 0
         match x:
-            case +0:
+            case 0:
                 y = 0
         self.assertEqual(x, 0)
         self.assertEqual(y, 0)
@@ -2941,7 +2941,7 @@ class TestPatma(unittest.TestCase):
     def test_patma_257(self):
         x = 0
         match x:
-            case +0.0:
+            case 0.0:
                 y = 0
         self.assertEqual(x, 0)
         self.assertEqual(y, 0)
@@ -2949,7 +2949,7 @@ class TestPatma(unittest.TestCase):
     def test_patma_258(self):
         x = 0
         match x:
-            case +0j:
+            case 0j:
                 y = 0
         self.assertEqual(x, 0)
         self.assertEqual(y, 0)
@@ -2957,7 +2957,7 @@ class TestPatma(unittest.TestCase):
     def test_patma_259(self):
         x = 0
         match x:
-            case +0.0j:
+            case 0.0j:
                 y = 0
         self.assertEqual(x, 0)
         self.assertEqual(y, 0)
@@ -2965,7 +2965,7 @@ class TestPatma(unittest.TestCase):
     def test_patma_260(self):
         x = 1
         match x:
-            case +1:
+            case 1:
                 y = 0
         self.assertEqual(x, 1)
         self.assertEqual(y, 0)
@@ -2973,7 +2973,7 @@ class TestPatma(unittest.TestCase):
     def test_patma_261(self):
         x = 1.5
         match x:
-            case +1.5:
+            case 1.5:
                 y = 0
         self.assertEqual(x, 1.5)
         self.assertEqual(y, 0)
@@ -2981,7 +2981,7 @@ class TestPatma(unittest.TestCase):
     def test_patma_262(self):
         x = 1j
         match x:
-            case +1j:
+            case 1j:
                 y = 0
         self.assertEqual(x, 1j)
         self.assertEqual(y, 0)
@@ -2989,7 +2989,7 @@ class TestPatma(unittest.TestCase):
     def test_patma_263(self):
         x = 1.5j
         match x:
-            case +1.5j:
+            case 1.5j:
                 y = 0
         self.assertEqual(x, 1.5j)
         self.assertEqual(y, 0)
@@ -2997,7 +2997,7 @@ class TestPatma(unittest.TestCase):
     def test_patma_264(self):
         x = 0.25 + 1.75j
         match x:
-            case +0.25 + 1.75j:
+            case 0.25 + 1.75j:
                 y = 0
         self.assertEqual(x, 0.25 + 1.75j)
         self.assertEqual(y, 0)
@@ -3005,7 +3005,7 @@ class TestPatma(unittest.TestCase):
     def test_patma_265(self):
         x = 0.25 - 1.75j
         match x:
-            case 0.25 - +1.75j:
+            case 0.25 - 1.75j:
                 y = 0
         self.assertEqual(x, 0.25 - 1.75j)
         self.assertEqual(y, 0)
@@ -3013,7 +3013,7 @@ class TestPatma(unittest.TestCase):
     def test_patma_266(self):
         x = 0
         match x:
-            case +1e1000:
+            case 1e1000:
                 y = 0
             case 0:
                 y = 1
