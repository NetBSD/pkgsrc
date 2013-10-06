# $NetBSD: Makefile,v 1.53 2013/10/06 16:09:00 wiz Exp $

DISTNAME=	libmikmod-3.3.2
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.shlomifish.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mikmod.raphnet.net/
COMMENT=	MikMod Sound Library
LICENSE=	gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		autoconf gmake makeinfo
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-threads

INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	libmikmod.pc.in

pre-configure:
	cd ${WRKSRC} && autoconf

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
