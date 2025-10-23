# $NetBSD: Makefile,v 1.80 2025/10/23 20:35:49 wiz Exp $

DISTNAME=	libmikmod-3.3.13
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mikmod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mikmod.sourceforge.net/
COMMENT=	MikMod Sound Library
LICENSE=	gnu-lgpl-v2

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-threads
INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	libmikmod.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
