# $NetBSD: Makefile,v 1.1.1.1 2004/07/06 14:39:15 xtraeme Exp $
#

DISTNAME=		gzrt-0.2
PKGNAME=		gzrecover-0.2
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
