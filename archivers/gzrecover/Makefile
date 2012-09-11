# $NetBSD: Makefile,v 1.8 2012/09/11 19:46:55 asau Exp $
#

DISTNAME=		gzrt-0.5
PKGNAME=		gzrecover-0.5
CATEGORIES=		archivers
MASTER_SITES=		http://www.urbanophile.com/arenn/hacking/gzrt/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.urbanophile.com/arenn/hacking/gzrt/
COMMENT=		GZip Recovery Toolkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=		gzrecover

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gzrecover ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
