#	$NetBSD: Makefile,v 1.3 2002/02/18 15:14:13 seb Exp $
# Makefile for libg++ add-on for NetBSD.  Requires libstdc++ shlib v1.x.

LIB=g++

SHLIB_MAJOR=5
SHLIB_MINOR=0

SRCS=	ACG.cc AllocRing.cc Binomial.cc BitSet.cc BitString.cc \
	DLList.cc DiscUnif.cc Erlang.cc Fix.cc Fix16.cc Fix24.cc Geom.cc \
	GetOpt.cc HypGeom.cc Intdouble.cc Integer.cc LogNorm.cc MLCG.cc \
	NegExp.cc Normal.cc Obstack.cc Poisson.cc RNG.cc Random.cc \
	Rational.cc Regex.cc RndInt.cc SLList.cc SmplHist.cc SmplStat.cc \
	String.cc Uniform.cc Weibull.cc builtin.cc compare.cc error.cc \
	fmtq.cc gcd.cc hash.cc ioob.cc lg.cc pow.cc sqrt.cc
SRCS+=	bitand.c bitany.c bitblt.c bitclear.c bitcopy.c bitcount.c \
	bitinvert.c bitlcomp.c bitset1.c bitxor.c timer.c
SRCS+=	rx.c

INCS=	ACG.h AllocRing.h Binomial.h BitSet.h BitString.h Complex.h \
	DLList.h DiscUnif.h Erlang.h Fix.h Fix16.h Fix24.h \
	Geom.h GetOpt.h HypGeom.h Incremental.h Integer.h LogNorm.h MLCG.h \
	NegExp.h Normal.h Obstack.h Pix.h Poisson.h RNG.h Random.h \
	Rational.h Regex.h RndInt.h SLList.h SmplHist.h SmplStat.h \
	String.h Uniform.h Weibull.h bitdo1.h bitdo2.h bitprims.h bool.h \
	builtin.h compare.h generic.h getpagesize.h libc.h minmax.h \
	osfcn.h std.h strclass.h swap.h sysent.h typemacros.h
INCS+=	gen/AVLMap.hP gen/AVLSet.hP gen/AVec.hP gen/BSTSet.hP gen/Bag.hP \
	gen/CHBag.hP gen/CHMap.hP gen/CHNode.hP gen/CHSet.hP \
	gen/DLDeque.hP gen/DLList.hP gen/Deque.hP gen/FPQueue.hP \
	gen/FPStack.hP gen/FPlex.hP gen/List.hP gen/MPlex.hP gen/Map.hP \
	gen/OSLBag.hP gen/OSLSet.hP gen/OXPBag.hP gen/OXPSet.hP \
	gen/PHPQ.hP gen/PQ.hP gen/PSList.hP gen/PVec.hP gen/Plex.hP \
	gen/Queue.hP gen/RAVLMap.hP gen/RPlex.hP gen/SLBag.hP \
	gen/SLList.hP gen/SLQueue.hP gen/SLSet.hP gen/SLStack.hP \
	gen/Set.hP gen/SkipBag.hP gen/SkipMap.hP gen/SkipSet.hP \
	gen/SplayBag.hP gen/SplayMap.hP gen/SplayNode.hP gen/SplayPQ.hP \
	gen/SplaySet.hP gen/Stack.hP gen/VHBag.hP gen/VHMap.hP \
	gen/VHSet.hP gen/VOHSet.hP gen/VQueue.hP gen/VStack.hP gen/Vec.hP \
	gen/XPBag.hP gen/XPDeque.hP gen/XPPQ.hP gen/XPQueue.hP \
	gen/XPSet.hP gen/XPStack.hP gen/XPlex.hP gen/defs.hP \
	gen/intSList.hP gen/intVec.hP
INCS+=	gen/AVLMap.ccP gen/AVLSet.ccP gen/AVec.ccP gen/BSTSet.ccP \
	gen/Bag.ccP gen/CHBag.ccP gen/CHMap.ccP gen/CHNode.ccP \
	gen/CHSet.ccP gen/DLDeque.ccP gen/DLList.ccP gen/Deque.ccP \
	gen/FPQueue.ccP gen/FPStack.ccP gen/FPlex.ccP gen/List.ccP \
	gen/MPlex.ccP gen/Map.ccP gen/OSLBag.ccP gen/OSLSet.ccP \
	gen/OXPBag.ccP gen/OXPSet.ccP gen/PHPQ.ccP gen/PQ.ccP gen/Plex.ccP \
	gen/Queue.ccP gen/RAVLMap.ccP gen/RPlex.ccP gen/SLBag.ccP \
	gen/SLList.ccP gen/SLQueue.ccP gen/SLSet.ccP gen/SLStack.ccP \
	gen/Set.ccP gen/SkipBag.ccP gen/SkipMap.ccP gen/SkipSet.ccP \
	gen/SplayBag.ccP gen/SplayMap.ccP gen/SplayNode.ccP \
	gen/SplayPQ.ccP gen/SplaySet.ccP gen/Stack.ccP gen/VHBag.ccP \
	gen/VHMap.ccP gen/VHSet.ccP gen/VOHSet.ccP gen/VQueue.ccP \
	gen/VStack.ccP gen/Vec.ccP gen/XPBag.ccP gen/XPDeque.ccP \
	gen/XPPQ.ccP gen/XPQueue.ccP gen/XPSet.ccP gen/XPStack.ccP \
	gen/XPlex.ccP

CPPFLAGS+=	-Ilibg++/src -Ilibrx
NOLINT=

BINDIR=		${PREFIX}/bin
INCSDIR=	${PREFIX}/include/g++
LIBDIR=		${PREFIX}/lib

genclass: libg++/genclass/genclass.sh
	sed -e "s,<VERSION>,${GXXVERSION},;s,^PROTODIR.*,PROTODIR=${PREFIX}/include/g++/gen," ${.ALLSRC} >${.TARGET}

libg++.info: libg++/libg++.texi
	${MAKEINFO} --no-split -I libg++/texinfo -o libg++.info libg++/libg++.texi

.PATH: libg++/src librx

.include <bsd.lib.mk>

all: genclass libg++.info
install: includes
