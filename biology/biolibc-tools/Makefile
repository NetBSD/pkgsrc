# $NetBSD: Makefile,v 1.10 2023/08/12 14:51:02 bacon Exp $

DISTNAME=	biolibc-tools-0.1.4.9
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	6d9604303fa43418a423840c916407af2b069184

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
