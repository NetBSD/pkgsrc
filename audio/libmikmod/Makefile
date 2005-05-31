# $NetBSD: Makefile,v 1.36 2005/05/31 16:10:19 wiz Exp $

DISTNAME=		libmikmod-3.1.11
PKGNAME=		libmikmod-3.1.11.1
PKGREVISION=		1
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
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
USE_MAKEINFO=		yes
INFO_FILES=		mikmod.info

CONFIGURE_ARGS+=	--disable-threads

.include "options.mk"

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

.include "../../mk/bsd.pkg.mk"
