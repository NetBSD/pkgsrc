$NetBSD: patch-source_maths_tests_test__Bound.h,v 1.1 2023/05/04 15:20:52 nikita Exp $


--- source/maths/tests/test_Bound.h.orig	2023-05-04 00:38:25.197319481 +0200
+++ source/maths/tests/test_Bound.h	2023-05-04 00:43:35.449226082 +0200
@@ -203,9 +203,9 @@
 		CBoundingBoxOriented result;
 		flatAabb.Transform(transform, result);
 
-		TS_ASSERT(!isnan(result.m_Basis[0].X) && !isnan(result.m_Basis[0].Y) && !isnan(result.m_Basis[0].Z));
-		TS_ASSERT(!isnan(result.m_Basis[1].X) && !isnan(result.m_Basis[1].Y) && !isnan(result.m_Basis[1].Z));
-		TS_ASSERT(!isnan(result.m_Basis[2].X) && !isnan(result.m_Basis[2].Y) && !isnan(result.m_Basis[2].Z));
+		TS_ASSERT(!std::isnan(result.m_Basis[0].X) && !std::isnan(result.m_Basis[0].Y) && !std::isnan(result.m_Basis[0].Z));
+		TS_ASSERT(!std::isnan(result.m_Basis[1].X) && !std::isnan(result.m_Basis[1].Y) && !std::isnan(result.m_Basis[1].Z));
+		TS_ASSERT(!std::isnan(result.m_Basis[2].X) && !std::isnan(result.m_Basis[2].Y) && !std::isnan(result.m_Basis[2].Z));
 	}
 
 	void test_point_visibility()
