# $NetBSD: Makefile,v 1.47 2019/04/29 17:13:15 adam Exp $

DISTNAME=	ccache-3.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ccache/}
# do not use xz distfile here, xz needs gettext-lib which leads to circular
# dependencies on some platforms.
EXTRACT_SUFX=	.tar.bz2
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
