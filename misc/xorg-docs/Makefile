# $NetBSD: Makefile,v 1.7 2006/01/18 23:53:06 xtraeme Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		xorg-docs-${XORG_VER}
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XORG}
DISTFILES+=		X11R${XORG_VER}-src1.tar.gz X11R${XORG_VER}-src6.tar.gz

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.x.org/
COMMENT=		X.org Documentation

BUILD_DEPENDS=		xorg-imake>=${XORG_VER}:../../x11/xorg-imake

USE_LANGUAGES=		# empty

XBUILD_DIRS=		doc/specs

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
