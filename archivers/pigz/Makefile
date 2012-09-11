# $NetBSD: Makefile,v 1.5 2012/09/11 19:47:00 asau Exp $
#

DISTNAME=	pigz-2.2.5
CATEGORIES=	archivers
MASTER_SITES=	http://zlib.net/pigz/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://zlib.net/pigz/
COMMENT=	Parallel implementation of gzip
LICENSE=	modified-bsd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/pigz

BUILD_TARGET=		pigz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pigz ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pigz
	${INSTALL_MAN} ${WRKSRC}/pigz.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
