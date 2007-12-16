# $NetBSD: Makefile,v 1.43 2007/12/16 14:25:35 heinz Exp $

DISTNAME=		libmikmod-3.1.11
PKGNAME=		libmikmod-3.1.11.1
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://mikmod.raphnet.net/files/

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		libmikmod-3.1.11-a.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=		kuebart@mathematik.uni-ulm.de
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
