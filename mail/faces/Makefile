# New ports collection makefile for:	faces-1.6.1
# Version required:	1.6.1
# Date created:		09 December 96
# Whom:			Lars Koeller <Lars_Koeller@odie.physik2.uni-rostock.de>
#			Andreas Klemm <andreas@FreeBSD.ORG>
#
# $NetBSD: Makefile,v 1.5 1998/03/08 02:31:57 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/17 18:47:53 max Exp
#

DISTNAME=	faces-1.6.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/faces/ \
		ftp://odie.physik2.uni-rostock.de/pub/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

WRKSRC=		${WRKDIR}/faces
MAN1=		compface.1 faces.1 face_update.1 uncompface.1
MAN3=		compface.3 uncompface.3

post-configure:
	@for f in ${WRKSRC}/Makefile ${WRKSRC}/faces.h ${WRKSRC}/x11.c; do \
		${MV} $$f $$f.in;					\
		${SED} -e 's|@localbase@|'${LOCALBASE}'|g' 		\
			-e 's|@x11base@|'${X11BASE}'|g' < $$f.in > $$f;	\
	done

PLIST_SRC=	${WRKDIR}/.PLIST-src

post-install:
	${LDCONFIG} || ${TRUE}
	${LN} -f ${PREFIX}/man/man1/compface.1 ${PREFIX}/man/man1/uncompface.1
	${LN} -f ${PREFIX}/man/man3/compface.3 ${PREFIX}/man/man3/uncompface.3
	@${SED} -e 's|@localbase@|'${LOCALBASE}'|g' \
		-e 's|@x11base@|'${X11BASE}'|g' < pkg/PLIST > ${PLIST_SRC}

.include <bsd.port.mk>
