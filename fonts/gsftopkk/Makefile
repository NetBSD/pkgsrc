# $NetBSD: Makefile,v 1.9 2015/04/25 13:40:05 markd Exp $

DISTNAME=	texlive-20140525-source
PKGNAME=	gsftopkk-1.19.2
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2014/
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

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CPPFLAGS+=	-DGS_PATH='"${TOOLS_PATH.gs}"'

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
