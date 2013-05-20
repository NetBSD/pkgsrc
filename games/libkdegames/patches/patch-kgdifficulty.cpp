$NetBSD: patch-kgdifficulty.cpp,v 1.1 2013/05/20 10:02:36 jperkin Exp $

GCC on SunOS does not like the typedef.

--- kgdifficulty.cpp.orig	2013-03-01 07:19:39.980651883 +0000
+++ kgdifficulty.cpp
@@ -195,22 +195,22 @@ void KgDifficulty::addLevel(KgDifficulty
 	level->setParent(this);
 }
 
-typedef KgDifficultyLevel::StandardLevel DS;
+//typedef KgDifficultyLevel::StandardLevel DS;
 
-void KgDifficulty::addStandardLevel(DS level, bool isDefault)
+void KgDifficulty::addStandardLevel(KgDifficultyLevel::StandardLevel level, bool isDefault)
 {
 	addLevel(new KgDifficultyLevel(level, isDefault));
 }
 
-void KgDifficulty::addStandardLevelRange(DS from, DS to)
+void KgDifficulty::addStandardLevelRange(KgDifficultyLevel::StandardLevel from, KgDifficultyLevel::StandardLevel to)
 {
 	//every level in range != Custom, therefore no level is default
 	addStandardLevelRange(from, to, KgDifficultyLevel::Custom);
 }
 
-void KgDifficulty::addStandardLevelRange(DS from, DS to, DS defaultLevel)
+void KgDifficulty::addStandardLevelRange(KgDifficultyLevel::StandardLevel from, KgDifficultyLevel::StandardLevel to, KgDifficultyLevel::StandardLevel defaultLevel)
 {
-	const QVector<DS> levels = QVector<DS>()
+	const QVector<KgDifficultyLevel::StandardLevel> levels = QVector<KgDifficultyLevel::StandardLevel>()
 		<< KgDifficultyLevel::RidiculouslyEasy
 		<< KgDifficultyLevel::VeryEasy
 		<< KgDifficultyLevel::Easy
