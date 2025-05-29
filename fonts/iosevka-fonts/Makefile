# $NetBSD: Makefile,v 1.1 2025/05/29 14:48:28 ryoon Exp $

DISTNAME=	SuperTTC-Iosevka-33.2.3
PKGNAME=	${DISTNAME:S/SuperTTC-//:S/Iosevka-/iosevka-fonts-/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=be5invis/}
GITHUB_PROJECT=	Iosevka
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://typeof.net/Iosevka/
COMMENT=	Versatile typeface for code, from code
LICENSE=	ofl-v1.1

DISTFILES=	${DEFAULT_DISTFILES}

VARIANTS=	Aile Curly CurlySlab Etoile Slab
VARIANTS+=	SS01 SS02 SS03 SS04 SS05 SS06 SS07 SS08 SS09
VARIANTS+=	SS10 SS11 SS12 SS13 SS14 SS15 SS16 SS17 SS18

.for v in ${VARIANTS}
IOSEVKAFNAME.${v}=		SuperTTC-Iosevka${v}-33.2.3${EXTRACT_SUFX}
DISTFILES+=			${IOSEVKAFNAME.${v}}
SITES.${IOSEVKAFNAME.${v}}=	${SITES.${_GITHUB_DEFAULT_DISTFILES}}
.endfor

WRKSRC=		${WRKDIR}

NO_BUILD=		yes
FONTSDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=		${FONTSDIR}
INSTALLATION_DIRS=	share/fonts/X11/TTF

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
