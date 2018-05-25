$NetBSD: patch-tests_test-patchbomb.t,v 1.1 2018/05/25 13:04:56 joerg Exp $

Merge 326b174c6a47 from upstream:
bundle2: mark the bundle2 part as advisory (issue5872)

--- tests/test-patchbomb.t.orig	2018-05-05 23:02:58.000000000 +0000
+++ tests/test-patchbomb.t
@@ -388,15 +388,15 @@ test bundle and description:
   Content-Disposition: attachment; filename="bundle.hg"
   Content-Transfer-Encoding: base64
   
-  SEcyMAAAAA5Db21wcmVzc2lvbj1CWkJaaDkxQVkmU1kHdO0GAAAN////vFcSXL9/8H7R09C/578I
-  Ak0E4pe4SIIIgQSgGEQOcLABGYYNKiaaZGEyYjJhGTTRpiHogxGmTRiGRkNMIwhhPSbQJtpQiJkn
-  poyk9I0PUeoNNNBkeUAHqGgD0Ro0NNBoBoaMagNBoNCpNPUemp6QGmgyaPSGmQxGhkZDQbUaBkHp
-  MhoaANNMhkIyIauvSJPL4aUXjIQemQXkoaqOKqAQDIABsZALnf0yCLAyvmktzDWBCVHO6bb6kCqE
-  ZobVEhmMBjs0oQzekgs6PgZSyII8zy9mmG9To49ZlN6TaX5BxlS7cJiuICUdyjNQPIIdQs1Qqqqk
-  JZ2/BksYcU4HQyssZcpkoMco6gRc888KF9BO7BvuSuIPz7A4crBoaQB+euFU1ilz8yIBBmNBDgRX
-  pVh4zkmPiSKcqRJxcshMqh0vkKlgQDTcOujtdmnMVBZfQiPPemcHm2098VJyHBAOqOwluyIKyG92
-  JAR0CCu9SB5q9DyPHUdc5yB5CurIZHt3GM0dCiQRIN0EAcQNmTYTiHdi6B6Dc/ma0hrmSCQXBzfU
-  BEwthEg0YGaJf4u5IpwoSAO6doMA
+  SEcyMAAAAA5Db21wcmVzc2lvbj1CWkJaaDkxQVkmU1l91TAVAAAN////vFcSXL9/8H7R09C/578I
+  Ak0E4pe4SIIIgQSgGEQOcLABGYYNKgJgmhpp6mmjIZMCZNMhpgBBpkaYJpo9QaZMg02iaY2lCImK
+  emk02kmEAeoA0D01ANBoHqHqADTaj1NAAyZqA0Gg0KiYnqaepk0eoNDTCGj1A0eoyBoGjRkYBqAB
+  poNMmhkBhENSP0knlYZbqyEIYxkFdpDUS6roBDMgAGhkAqd92kEcgyeMo2MM366gpLNHjfKrhJPN
+  vdBCHAEDsYzAvzkHKxy5KWBAmh5e1nFttGChpsxrgmutRG0YrsSLWEBH9h95cbZEKFeUKYykRXHa
+  Bkt2OSgELsqqnWKeMudBR+YSZCOSHrwPz7B/Gfou7/L6QV6S0IgclBCitBVHMxMFq/vGwp5WHezM
+  JwhKTnH0OkMbmVjrAkQKR7VM2aNSXn+GzLOCzOQm0AJ1TLCpdSgnfFPcY7mGxAOyHXS1YEFVi5O9
+  I4EVBBd8VRgN4n1MAm8l6QQ+yB60hkeX/0ZZmKoQRINkEBxEDZU2HjIZMcwWRvZtbRIa5kgkGIb/
+  SkImFwIkDtQxyX+LuSKcKEg+6pgKgA==
   --===============*==-- (glob)
 
 with a specific bundle type
