# $NetBSD: Makefile,v 1.3 2004/10/03 00:14:47 tv Exp $
#

DISTNAME=	hugov30_unix_source
PKGNAME=	wxhugo-3.0.07
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.ifarchive.org/if-archive/programming/hugo/source/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTFILE_WX}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://161.184.245.22/tessman/gcc/hugo.html
COMMENT=	Interactive fiction interpreter with sound and graphics support

DISTFILE_WX=	hugov30_wxwin_source${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

DIST_SUBDIR=	hugo-3.0.07
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
WRKSRC=		${WRKDIR}/hugov3.0.07/hewx

LIBDIR=		${PREFIX}/share/hugo

post-extract:
	extract_file="${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_WX}"; export extract_file;    \
	cd ${WRKSRC}/.. && ${EXTRACT_CMD.tar.gz}
	for f in hejpeg.cpp hesound.cpp hesound_SDL.cpp hewxwin.cpp; \
	do \
		{ cd ${WRKSRC} && ${MV} $$f $$f.dos \
			&& ${TR} -d '\015' < $$f.dos > $$f; }; \
	done
	for f in hevideo.cpp; \
	do \
		{ cd ${WRKSRC} && ${MV} $$f $$f.mac \
			&& ${TR} '\015' '\012' < $$f.mac > $$f; }; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hewx ${PREFIX}/bin

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
