# $NetBSD: Makefile,v 1.16 1999/01/04 23:29:46 frueauf Exp $
# FreeBSD Id: Makefile,v 1.14 1997/07/03 07:37:08 asami Exp
#

DISTNAME=	xv-3.10a
CATEGORIES=     graphics x11
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/ \
		ftp://ftp.kuis.kyoto-u.ac.jp/X11/contrib/clients/xv/ \
		ftp://ftp.tohoku.ac.jp/pub/X/app/xv/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		xv310a-magpic2-PhotoCD-patch.tar.gz # only from Japan

PATCH_SITES=    ftp://ftp.cis.upenn.edu/pub/xv/
PATCHFILES=     xv-3.10a.JPEG-patch xv-3.10a.TIFF-patch # (for tiff3.4)

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-vis.lbl.gov/software/xv.html

DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	ghostscript-5.50:../../print/ghostscript5

USE_IMAKE=	yes

LICENSE=	shareware

.include "../../mk/bsd.prefs.mk"

pre-patch:
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/Patch.magpic2.PhotoCD.XV310a

post-patch:
	${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.bak
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g' < ${WRKSRC}/config.h.bak \
		> ${WRKSRC}/config.h

post-install:
	${MKDIR} ${PREFIX}/share/doc/xv
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xv
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/docs/xvdocs.ps ${PREFIX}/share/doc/xv
.endif

.include "../../mk/bsd.pkg.mk"
