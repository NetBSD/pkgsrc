# $NetBSD: Makefile,v 1.7 2010/07/06 10:17:11 jmmv Exp $
#

DISTNAME=		gzrt-0.5
PKGNAME=		gzrecover-0.5
CATEGORIES=		archivers
MASTER_SITES=		http://www.urbanophile.com/arenn/hacking/gzrt/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.urbanophile.com/arenn/hacking/gzrt/
COMMENT=		GZip Recovery Toolkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		gzrecover

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gzrecover ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
