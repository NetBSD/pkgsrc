#	$NetBSD: Makefile,v 1.1 1997/12/13 19:48:14 agc Exp $

LIB=		mpeg
LIBDIR=		${PREFIX}/lib
CPPFLAGS+=	-DHAVE_CONFIG_H -I.

INCS=		mpeg.h
INCSDIR=	${PREFIX}/include

SRCS=	util.c video.c parseblock.c motionvector.c decoders.c jrevdct.c\
	wrapper.c globals.c 24bit.c gdith.c fs2.c fs2fast.c fs4.c hybrid.c\
	hybriderr.c 2x2.c gray.c mono.c ordered.c ordered2.c mb_ordered.c

.include <bsd.lib.mk>
