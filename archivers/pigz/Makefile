# $NetBSD: Makefile,v 1.9 2016/10/02 09:06:11 fhajny Exp $

DISTNAME=	pigz-2.3.4
CATEGORIES=	archivers
MASTER_SITES=	http://zlib.net/pigz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zlib.net/pigz/
COMMENT=	Parallel implementation of gzip
LICENSE=	modified-bsd

USE_LANGUAGES=	c c99
USE_TOOLS+=	gmake

BUILD_TARGET=		pigz
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/pigz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pigz ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pigz
	${INSTALL_MAN} ${WRKSRC}/pigz.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
