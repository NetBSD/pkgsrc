# $NetBSD: Makefile,v 1.2 2023/01/19 15:41:40 gdt Exp $

DISTNAME=	ccache-3.7.12
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ccache/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
# We choose gzip to minimize dependencies; some platforms do not have
# xz builtin.

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ccache.dev/
COMMENT=	Cache for C/C++ compilers
LICENSE=	gnu-gpl-v3 AND modified-bsd AND public-domain AND zlib

USE_TOOLS+=	bash:test gmake perl:test
GNU_CONFIGURE=	yes
TEST_TARGET=	test

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
