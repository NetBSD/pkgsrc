# $NetBSD: Makefile,v 1.10 1999/01/26 22:03:20 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/17 18:47:53 max Exp
#

DISTNAME=	faces-1.6.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/faces/ \
		ftp://odie.physik2.uni-rostock.de/pub/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

WRKSRC=		${WRKDIR}/faces

BUILD_USES_X11=	yes

post-configure:
	@for f in ${WRKSRC}/Makefile ${WRKSRC}/faces.h ${WRKSRC}/x11.c; do \
		${MV} $$f $$f.in;					\
		${SED} -e 's|@localbase@|'${LOCALBASE}'|g' 		\
			-e 's|@x11base@|'${X11BASE}'|g' < $$f.in > $$f;	\
	done

PLIST_SRC=	${WRKDIR}/.PLIST-src

post-install:
	${LN} -f ${PREFIX}/man/man1/compface.1 ${PREFIX}/man/man1/uncompface.1
	${LN} -f ${PREFIX}/man/man3/compface.3 ${PREFIX}/man/man3/uncompface.3
	@${SED} -e 's|@localbase@|'${LOCALBASE}'|g' \
		-e 's|@x11base@|'${X11BASE}'|g' < ${PKGDIR}/PLIST > ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
