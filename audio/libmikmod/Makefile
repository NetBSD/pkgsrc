# $NetBSD: Makefile,v 1.75 2023/05/06 19:09:01 ryoon Exp $

DISTNAME=	libmikmod-3.3.11.1
PKGREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mikmod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mikmod.sourceforge.net/
COMMENT=	MikMod Sound Library
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-threads

INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	libmikmod.pc.in

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
