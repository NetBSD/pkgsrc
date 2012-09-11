# $NetBSD: Makefile,v 1.52 2012/09/12 00:24:42 asau Exp $

DISTNAME=	libmikmod-3.2.0
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

pre-configure:
	cd ${WRKSRC} && autoconf

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
