# $NetBSD: Makefile,v 1.36 2001/05/22 09:32:23 wiz Exp $
# FreeBSD Id: Makefile,v 1.14 1997/07/03 07:37:08 asami Exp
#

DISTNAME=	xv-3.10a
PKGNAME=	${DISTNAME}nb1
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
DEPENDS+=	tiff-*:../../graphics/tiff

USE_IMAKE=	yes

LICENSE=	shareware

.include "../../mk/bsd.prefs.mk"

pre-patch:
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/Patch.magpic2.PhotoCD.XV310a

post-patch:
	${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.bak
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g' < ${WRKSRC}/config.h.bak \
		> ${WRKSRC}/config.h

.if ${OPSYS} == "SunOS"
pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} xvinfo.o CC=cc
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xv
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xv
	${INSTALL_DATA} ${WRKSRC}/docs/xvdocs.ps ${PREFIX}/share/doc/xv

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=
LDFLAGS+=	-Wl,-R${X11BASE}/lib
.endif

.include "../../mk/bsd.pkg.mk"
