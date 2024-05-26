# $NetBSD: Makefile,v 1.4 2024/05/26 10:39:42 pho Exp $

DISTNAME=	pkgchkxx-0.2.1
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=depressed-pho/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/depressed-pho/pkgchkxx
COMMENT=	Complete rewrite of pkg_chk and pkg_rolling-replace in C++
LICENSE=	modified-bsd AND 2-clause-bsd

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17 filesystem unique_ptr
USE_TOOLS=		gmake
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-doxygen

# These are runtime dependencies and therefore must not contain references
# to ${WRKDIR}.
CONFIGURE_ARGS+=	BMAKE=${MAKE}
CONFIGURE_ARGS+=	PKG_CONFIG=${PREFIX}/bin/pkgconf
CONFIGURE_ARGS+=	PKG_CONFIG_LIBDIR=	# empty
CONFIGURE_ARGS+=	PKG_CONFIG_PATH=	# empty
CONFIGURE_ENV+=		XARGS=/usr/bin/xargs

DEPENDS+=	pkg_install>=20211115:../../pkgtools/pkg_install
DEPENDS+=	pkgconf>=1.9.4:../../devel/pkgconf

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libfetch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
