$NetBSD: patch-h5py_tests_test__dataset.py,v 1.1 2023/12/13 20:29:09 wiz Exp $

Fix build with Cython 3.
https://github.com/h5py/h5py/pull/2345

--- h5py/tests/test_dataset.py.orig	2023-10-04 09:21:14.000000000 +0000
+++ h5py/tests/test_dataset.py
@@ -1939,9 +1939,9 @@ class TestCommutative(BaseDataset):
         dset = self.f.create_dataset("test", shape, dtype=float,
                                      data=np.random.rand(*shape))
 
-        # grab a value from the elements, ie dset[0]
+        # grab a value from the elements, ie dset[0, 0]
         # check that mask arrays are commutative wrt ==, !=
-        val = np.float64(dset[0])
+        val = np.float64(dset[0, 0])
 
         assert np.all((val == dset) == (dset == val))
         assert np.all((val != dset) == (dset != val))
