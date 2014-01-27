# $NetBSD: Makefile,v 1.56 2014/01/27 20:19:17 wiz Exp $

DISTNAME=	libmikmod-3.3.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mikmod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mikmod.sourceforge.net/
COMMENT=	MikMod Sound Library
LICENSE=	gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		autoconf gmake makeinfo
USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-threads

INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	libmikmod.pc.in

pre-configure:
	cd ${WRKSRC} && autoconf

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
