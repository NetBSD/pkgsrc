# $NetBSD: Makefile,v 1.40 2001/11/29 01:12:37 hubertf Exp $

DISTNAME=	xv-3.10a
PKGREVISION=	1
CATEGORIES=     graphics x11
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/ \
		ftp://ftp.kuis.kyoto-u.ac.jp/X11/contrib/clients/xv/ \
		ftp://ftp.tohoku.ac.jp/pub/X/app/xv/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		xv310a-magpic2-PhotoCD-patch.tar.gz # only from Japan

PATCH_SITES=    ftp://ftp.cis.upenn.edu/pub/xv/
PATCHFILES=     xv-3.10a.JPEG-patch xv-3.10a.TIFF-patch # (for tiff3.4)

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.trilon.com/xv/
COMMENT=	X11 program that displays images of various formats

DEPENDS+=	png>=1.0.11:../png
DEPENDS+=	tiff-[0-9]*:../../graphics/tiff

USE_IMAKE=	YES

LICENSE=	shareware

.include "../../mk/bsd.prefs.mk"

pre-patch:
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/Patch.magpic2.PhotoCD.XV310a

post-patch:
	${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.bak
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g' < ${WRKSRC}/config.h.bak \
		> ${WRKSRC}/config.h

.if ${OPSYS} == "SunOS"
post-configure:
	cd ${WRKSRC} && \
	${MV} ${MAKEFILE} ${MAKEFILE}.old && \
	${SED} -e 's# CC = .*# CC = ${CC}#' \
	  -e 's# CCOPTIONS = .*# CCOPTIONS = ${CFLAGS}'# \
	  -e 's# CDEBUGFLAGS = .*# CDEBUGFLAGS =#' \
	  ${MAKEFILE}.old >${MAKEFILE}
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xv
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xv
	${INSTALL_DATA} ${WRKSRC}/docs/xvdocs.ps ${PREFIX}/share/doc/xv

.include "../../mk/bsd.pkg.mk"
