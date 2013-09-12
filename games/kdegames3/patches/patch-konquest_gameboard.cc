$NetBSD: patch-konquest_gameboard.cc,v 1.1 2013/09/12 20:11:30 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- konquest/gameboard.cc.orig	2005-09-10 08:18:23.000000000 +0000
+++ konquest/gameboard.cc
@@ -405,7 +405,7 @@ GameBoard::turn()
 						}
                                                 if (skip) continue;
 
-                                                shipsToSend = (int)floor((home->getFleet().getShipCount() - attack->getFleet().getShipCount()) / 2) ;
+                                                shipsToSend = (int)floor((float)(home->getFleet().getShipCount() - attack->getFleet().getShipCount()) / 2) ;
                                                 
 					  	target = attack;
 					   	hasDestination = true;
