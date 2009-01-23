# $NetBSD: Makefile,v 1.45 2009/01/23 20:25:28 kefren Exp $

DISTNAME=		libmikmod-3.1.11
PKGNAME=		libmikmod-3.1.11.1
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://mikmod.raphnet.net/files/

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		libmikmod-3.1.11-a.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=		pkgsrc-users@netbsd.org
HOMEPAGE=		http://mikmod.raphnet.net/
COMMENT=		MikMod Sound Library

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--disable-threads

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
