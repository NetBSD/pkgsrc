# $NetBSD: Makefile,v 1.7 1998/04/15 10:38:28 agc Exp $
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

LIB_DEPENDS=    jpeg.7.:${PORTSDIR}/graphics/jpeg \
		tiff.3.4:${PORTSDIR}/graphics/tiff

USE_IMAKE=	yes

CAT1=		bggen.0 vdcomp.0 xcmap.0 xv.0 xvpictoppm.0

pre-patch:
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/Patch.magpic2.PhotoCD.XV310a

pre-configure:
	for f in `find ${WRKDIR} -name Imakefile -follow -print`; do \
		${SED} -e 's:/usr/local:'${LOCALBASE}':g' < $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done

post-install:
	${MKDIR} ${PREFIX}/share/doc/xv
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xv
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/docs/xvdocs.ps ${PREFIX}/share/doc/xv
.endif

.include "../../mk/bsd.pkg.mk"
