# $NetBSD: Makefile,v 1.10 2014/11/20 07:41:06 mef Exp $
#

DISTNAME=		gzrt-0.8
PKGNAME=		gzrecover-0.8
CATEGORIES=		archivers
MASTER_SITES=		http://www.urbanophile.com/arenn/hacking/gzrt/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.urbanophile.com/arenn/hacking/gzrt/
COMMENT=		GZip Recovery Toolkit
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		gzrecover

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gzrecover ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
