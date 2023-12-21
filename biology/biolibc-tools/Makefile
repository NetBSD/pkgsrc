# $NetBSD: Makefile,v 1.12 2023/12/21 08:50:24 nros Exp $

DISTNAME=	biolibc-tools-0.1.4.13
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	0375b83239ea352a708112ad1dc87606c174f11f

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/biolibc-tools
COMMENT=	High-performance bioinformatics tools based on biolibc
LICENSE=	2-clause-bsd

BUILD_TARGET=	depend all
MAKE_ENV+=	VERSION=${PKGVERSION}
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}
INSTALL_TARGET=	install-strip

LDFLAGS.SunOS+=		-lresolv -lsocket -lnsl

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
