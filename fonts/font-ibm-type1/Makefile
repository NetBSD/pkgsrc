# $NetBSD: Makefile,v 1.10 2023/02/28 07:08:02 wiz Exp $

DISTNAME=		font-ibm-type1-1.0.4
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		IBM Courier Type1 fonts

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		FCCACHE=${TOOLS_CMD.true:Q}

FONTS_DIRS.type1=	share/fonts/X11/Type1
FONTS_DIRS.x11=		share/fonts/X11/Type1

.include "../../mk/bsd.pkg.mk"
