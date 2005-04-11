# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:40 tv Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		xorg-docs-${XORG_VER}
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XORG}
DISTFILES+=		X11R6.7.0-src1.tar.gz X11R6.7.0-src6.tar.gz

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.x.org/
COMMENT=		X.org Documentation

BUILD_DEPENDS=		xorg-imake>=${XORG_VER}:../../x11/xorg-imake

USE_LANGUAGES=		# empty
NO_XFREE86_TARGETS=	# defined

XBUILD_DIRS=		doc/specs

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
