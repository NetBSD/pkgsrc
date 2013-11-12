# $NetBSD: Makefile,v 1.7 2013/11/12 21:07:03 minskim Exp $

DISTNAME=	texlive-20130530-source
PKGNAME=	gsftopkk-1.19.2
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://math.berkeley.edu/~vojta/gsftopk.html
COMMENT=	Tool to convert bitmaps to .pk format

CONFLICTS+=	teTeX-bin<=3.0nb34

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/gsftopk

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gs:run
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/gsftopk

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CPPFLAGS+=	-DGS_PATH='"${TOOLS_PATH.gs}"'

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
