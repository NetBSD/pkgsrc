# $NetBSD: Makefile,v 1.47 2010/03/22 11:22:23 obache Exp $

DISTNAME=		libmikmod-3.1.11
PKGNAME=		libmikmod-3.1.11.1
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://mikmod.raphnet.net/files/

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		libmikmod-3.1.11-a.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mikmod.raphnet.net/
COMMENT=		MikMod Sound Library
LICENSE=		gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes

CONFIGURE_ARGS+=	--disable-threads

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
