# $NetBSD: Makefile,v 1.9 2016/06/16 04:11:50 markd Exp $

DISTNAME=	texlive-20160523-source
PKGNAME=	mendexk-2.6f
PKGREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2016/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Replacement for makeindex with many enhancements
LICENSE=	modified-bsd

CONFLICTS+=	ja-ptex-bin-[0-9]*

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/mendexk

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/mendexk

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-ptexenc

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
BUILDLINK_API_DEPENDS.ptexenc+= ptexenc>=1.3.3
.include "../../print/ptexenc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
