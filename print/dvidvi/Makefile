# $NetBSD: Makefile,v 1.15 2018/05/13 12:24:31 markd Exp $
#

DISTNAME=	texlive-20180414-source
PKGNAME=	dvidvi-1.1
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2018/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Select and/or rearrange pages in a TeX dvi file

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/dvidvi

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dvidvi

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_DEPMETHOD.kpathsea=	build
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
