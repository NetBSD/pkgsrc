$NetBSD: patch-include_VotingArbiter.h,v 1.1 2013/02/26 10:29:06 joerg Exp $

--- include/VotingArbiter.h.orig	2013-02-25 16:00:51.000000000 +0000
+++ include/VotingArbiter.h
@@ -231,11 +231,11 @@ public:
 };
 
 
-inline VotingArbiter::VotingArbiter(unsigned short int voteTime=60,
-				    unsigned short int vetoTime=20,
-				    unsigned short int votesRequired=2,
-				    float votePercentage=50.1,
-				    unsigned short int voteRepeatTime=300)
+inline VotingArbiter::VotingArbiter(unsigned short int voteTime,
+				    unsigned short int vetoTime,
+				    unsigned short int votesRequired,
+				    float votePercentage,
+				    unsigned short int voteRepeatTime)
   : _votingBooth(NULL),
     _maxVotes(votesRequired+1),
     _voteTime(voteTime),
