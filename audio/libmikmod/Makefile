# $NetBSD: Makefile,v 1.38 2006/02/05 23:08:10 joerg Exp $

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

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_MAKEINFO=		yes
INFO_FILES=		mikmod.info

CONFIGURE_ARGS+=	--disable-threads

.include "options.mk"

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

.include "../../mk/bsd.pkg.mk"
