# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:04 tv Exp $
#

DISTNAME=		gzrt-0.2
PKGNAME=		gzrecover-0.2
PKGREVISION=	1
CATEGORIES=		archivers
MASTER_SITES=		http://www.urbanophile.com/arenn/hacking/gzrt/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.urbanophile.com/arenn/hacking/gzrt/
COMMENT=		GZip Recovery Toolkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ALL_TARGET=		gzrecover
USE_BUILDLINK3=		yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gzrecover ${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
