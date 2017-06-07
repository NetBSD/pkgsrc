$NetBSD: patch-README.rst,v 1.5 2017/06/07 10:21:34 he Exp $

Work around setup.py reading this file in a C locale.
https://github.com/ncclient/ncclient/issues/160

--- README.rst.orig	2016-12-28 07:44:45.000000000 +0000
+++ README.rst
@@ -175,7 +175,7 @@ Acknowledgements
    `Ebben Aries`_, `Einar Nilsen-Nygaard`_, `QijunPan`_
 -  v0.5.2: `Nitin Kumar`_, `Kristian Larsson`_, `palashgupta`_,
    `Jonathan Provost`_, `Jainpriyal`_, `sharang`_, `pseguel`_,
-   `nnakamot`_, `Алексей Пастухов`_, `Christian Giese`_, `Peipei Guo`_,
+   `nnakamot`_, `Alexei Pastuchov`_, `Christian Giese`_, `Peipei Guo`_,
    `Time Warner Cable Openstack Team`_
 -  v0.4.7: `Einar Nilsen-Nygaard`_, `Vaibhav Bajpai`_, Norio Nakamoto
 -  v0.4.6: `Nitin Kumar`_, `Carl Moberg`_, `Stavros Kroustouris`_
@@ -196,7 +196,7 @@ Acknowledgements
 .. _sharang: https://github.com/sharang
 .. _pseguel: https://github.com/pseguel
 .. _nnakamot: https://github.com/nnakamot
-.. _Алексей Пастухов: https://github.com/p-alik
+.. _Alexei Pastuchov: https://github.com/p-alik
 .. _Christian Giese: https://github.com/GIC-de
 .. _Peipei Guo: https://github.com/peipeiguo
 .. _Time Warner Cable Openstack Team: https://github.com/twc-openstack
