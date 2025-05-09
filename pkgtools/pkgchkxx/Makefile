# $NetBSD: Makefile,v 1.14 2025/05/09 14:53:22 tnn Exp $

DISTNAME=	pkgchkxx-0.3.3
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=depressed-pho/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/depressed-pho/pkgchkxx
COMMENT=	Complete rewrite of pkg_chk and pkg_rolling-replace in C++
LICENSE=	modified-bsd AND 2-clause-bsd

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17 filesystem
USE_TOOLS=		gmake pkg-config
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-doxygen
CONFIGURE_ARGS+=	LIBFETCH_CFLAGS="-I${BUILDLINK_PREFIX.libfetch}/include"
CONFIGURE_ARGS+=	LIBFETCH_LIBS="-L${BUILDLINK_PREFIX.libfetch}/lib -lfetch"

# These are runtime dependencies and therefore must not contain references
# to ${WRKDIR}.
CONFIGURE_ARGS+=	BMAKE=${MAKE}
CONFIGURE_ARGS+=	PKG_CONFIG=${PREFIX}/bin/pkgconf
CONFIGURE_ARGS+=	PKG_CONFIG_LIBDIR=	# empty
CONFIGURE_ARGS+=	PKG_CONFIG_PATH=	# empty
CONFIGURE_ENV+=		XARGS=/usr/bin/xargs

.include "../../mk/bsd.prefs.mk"

.if ${PKGTOOLS_VERSION} < 20211115
DEPENDS+=		pkg_install>=20211115:../../pkgtools/pkg_install
CONFIGURE_ARGS+=	PKG_ADD=${PREFIX}/sbin/pkg_add
CONFIGURE_ARGS+=	PKG_ADMIN=${PREFIX}/sbin/pkg_admin
CONFIGURE_ARGS+=	PKG_DELETE=${PREFIX}/sbin/pkg_delete
CONFIGURE_ARGS+=	PKG_INFO=${PREFIX}/bin/pkg_info
.endif
DEPENDS+=	pkgconf>=1.9.4:../../devel/pkgconf

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libfetch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
