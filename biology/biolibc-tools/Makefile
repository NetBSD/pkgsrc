# $NetBSD: Makefile,v 1.9 2023/06/14 18:43:33 bacon Exp $

DISTNAME=	biolibc-tools-0.1.4.6
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	b221258195460922eb461cfee58e7f329fdb4fe7

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/biolibc-tools
COMMENT=	High-performance bioinformatics tools based on biolibc
LICENSE=	2-clause-bsd

BUILD_TARGET=	depend all
MAKE_ENV+=	VERSION=${PKGVERSION}
INSTALL_TARGET=	install-strip

LDFLAGS.SunOS+=		-lresolv -lsocket -lnsl

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
