# $NetBSD: Makefile,v 1.3 2010/01/25 00:09:45 zafer Exp $
#

DISTNAME=	pigz-2.1.6
CATEGORIES=	archivers
MASTER_SITES=	http://zlib.net/pigz/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://zlib.net/pigz/
COMMENT=	Parallel implementation of gzip
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin share/doc/pigz

BUILD_TARGET=		pigz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pigz ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pigz

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
