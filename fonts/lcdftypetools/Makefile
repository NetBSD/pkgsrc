# $NetBSD: Makefile,v 1.4 2016/10/27 11:02:41 wiz Exp $

DISTNAME=	texlive-20160523-source
PKGNAME=	lcdftypetools-2.105
CATEGORIES=	fonts
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2016/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/lcdf-typetools
COMMENT=	Outline font manipulation tools
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-glyphlist-[0-9]*:../../fonts/tex-glyphlist

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/lcdf-typetools

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/lcdf-typetools

CXXFLAGS+=	-std=c++11

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
