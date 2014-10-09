# $NetBSD: Makefile,v 1.9 2014/10/09 14:05:51 wiz Exp $
#

DISTNAME=		gzrt-0.5
PKGNAME=		gzrecover-0.5
CATEGORIES=		archivers
MASTER_SITES=		http://www.urbanophile.com/arenn/hacking/gzrt/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.urbanophile.com/arenn/hacking/gzrt/
COMMENT=		GZip Recovery Toolkit

BUILD_TARGET=		gzrecover

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gzrecover ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
