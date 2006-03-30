# $NetBSD: Makefile,v 1.41 2006/03/30 03:44:41 jlam Exp $

DISTNAME=		libmikmod-3.1.11
PKGNAME=		libmikmod-3.1.11.1
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://mikmod.raphnet.net/files/

PATCHFILES=		libmikmod-3.1.11-a.diff
PATCH_SITES=		${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=		kuebart@mathematik.uni-ulm.de
HOMEPAGE=		http://mikmod.raphnet.net/
COMMENT=		MikMod Sound Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--disable-threads

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
