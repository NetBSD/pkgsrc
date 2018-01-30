# $NetBSD: Makefile,v 1.40 2018/01/30 05:43:19 adam Exp $

DISTNAME=	ccache-3.3.6
CATEGORIES=	devel
MASTER_SITES=	http://samba.org/ftp/ccache/
# do not use xz distfile here, xz needs gettext-lib which leads to circular
# dependencies on some platforms.
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ccache.samba.org/
COMMENT=	Cache for C/C++ compilers
LICENSE=	gnu-gpl-v3 AND modified-bsd AND public-domain AND zlib

GNU_CONFIGURE=		yes
TEST_TARGET=		test

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
