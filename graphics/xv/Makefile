# $NetBSD: Makefile,v 1.50 2003/09/17 19:40:40 grant Exp $

DISTNAME=	xv-3.10a
PKGREVISION=	5
CATEGORIES=     graphics x11
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/ \
		ftp://ftp.kuis.kyoto-u.ac.jp/X11/contrib/clients/xv/ \
		ftp://ftp.tohoku.ac.jp/pub/X/app/xv/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		xv310a-magpic2-PhotoCD-patch.tar.gz # only from Japan

PATCH_SITES=    ftp://ftp.cis.upenn.edu/pub/xv/
PATCHFILES=     xv-3.10a.JPEG-patch xv-3.10a.TIFF-patch # (for tiff3.4)

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.trilon.com/xv/
COMMENT=	X11 program that displays images of various formats

USE_BUILDLINK2=	YES

USE_IMAKE=	YES

LICENSE=	shareware

.include "../../mk/bsd.prefs.mk"

pre-patch:
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/Patch.magpic2.PhotoCD.XV310a

post-patch:
	${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.orig &&		\
		${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g'		\
		${WRKSRC}/config.h.orig > ${WRKSRC}/config.h

.if ${OPSYS} == "SunOS"
post-configure:
	${MV} ${WRKSRC}/${MAKEFILE} ${WRKSRC}/${MAKEFILE}.orig &&	\
		${SED} -e 's| CC = .*| CC = ${CC}|'			\
		-e 's| CCOPTIONS = .*| CCOPTIONS = ${CFLAGS}|'		\
		-e 's| CDEBUGFLAGS = .*| CDEBUGFLAGS =|'		\
		${WRKSRC}/${MAKEFILE}.orig > ${WRKSRC}/${MAKEFILE}
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xv
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xv
	${INSTALL_DATA} ${WRKSRC}/docs/xvdocs.ps ${PREFIX}/share/doc/xv

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
