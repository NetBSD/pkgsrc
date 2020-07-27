# $NetBSD: Makefile,v 1.59 2020/07/27 16:04:38 adam Exp $

DISTNAME=	ccache-3.7.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ccache/}
# do not use xz distfile here, xz needs gettext-lib which leads to circular
# dependencies on some platforms.
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ccache.dev/
COMMENT=	Cache for C/C++ compilers
LICENSE=	gnu-gpl-v3 AND modified-bsd AND public-domain AND zlib

USE_TOOLS+=		bash:test gmake perl:test
GNU_CONFIGURE=		yes
TEST_TARGET=		test

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
