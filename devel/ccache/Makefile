# $NetBSD: Makefile,v 1.45 2019/01/04 23:43:23 adam Exp $

DISTNAME=	ccache-3.5.1a
PKGNAME=	ccache-3.5.1
CATEGORIES=	devel
MASTER_SITES=	http://samba.org/ftp/ccache/
# do not use xz distfile here, xz needs gettext-lib which leads to circular
# dependencies on some platforms.
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ccache.samba.org/
COMMENT=	Cache for C/C++ compilers
LICENSE=	gnu-gpl-v3 AND modified-bsd AND public-domain AND zlib

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=		bash:test gmake perl:test
GNU_CONFIGURE=		yes
TEST_TARGET=		test

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
