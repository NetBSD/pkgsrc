$NetBSD: patch-Main_Source_rain.cpp,v 1.1 2014/02/09 17:09:03 wiedi Exp $

fix ambiguous math functions on SunOS
--- Main/Source/rain.cpp.orig	2004-10-26 19:37:04.000000000 +0000
+++ Main/Source/rain.cpp
@@ -12,7 +12,7 @@
 
 /* Compiled through materset.cpp */
 
-rain::rain(liquid* Liquid, lsquare* LSquareUnder, v2 Speed, int Team, truth OwnLiquid) : entity(OwnLiquid ? HAS_BE : 0), Next(0), Drop(0), Liquid(Liquid), LSquareUnder(LSquareUnder), Speed(Speed), SpeedAbs(long(sqrt(Speed.GetLengthSquare()))), Drops(0), OwnLiquid(OwnLiquid), Team(Team)
+rain::rain(liquid* Liquid, lsquare* LSquareUnder, v2 Speed, int Team, truth OwnLiquid) : entity(OwnLiquid ? HAS_BE : 0), Next(0), Drop(0), Liquid(Liquid), LSquareUnder(LSquareUnder), Speed(Speed), SpeedAbs(long(sqrt((double)Speed.GetLengthSquare()))), Drops(0), OwnLiquid(OwnLiquid), Team(Team)
 {
   Emitation = Liquid->GetEmitation();
   BeCounter = RAND_N(50);
@@ -164,7 +164,7 @@ void rain::Load(inputfile& SaveFile)
   Emitation = Liquid->GetEmitation();
   SaveFile >> Speed;
   Team = ReadType<uchar>(SaveFile);
-  SpeedAbs = long(sqrt(Speed.GetLengthSquare()));
+  SpeedAbs = long(sqrt((double)Speed.GetLengthSquare()));
 }
 
 outputfile& operator<<(outputfile& SaveFile, const rain* Rain)
