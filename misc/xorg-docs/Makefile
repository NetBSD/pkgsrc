# $NetBSD: Makefile,v 1.8 2006/02/12 15:29:18 xtraeme Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		xorg-docs-${XORG_VER}
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XORG}
DISTFILES+=		X11R${XORG_VER}-src1.tar.gz X11R${XORG_VER}-src6.tar.gz

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.x.org/
COMMENT=		X.org Documentation

BUILD_DEPENDS=		xorg-imake>=${XORG_VER}:../../x11/xorg-imake

USE_LANGUAGES=		# empty

XBUILD_DIRS=		doc/specs

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
