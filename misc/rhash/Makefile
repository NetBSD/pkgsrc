# $NetBSD: Makefile,v 1.24 2024/05/15 14:06:39 nia Exp $

DISTNAME=	rhash-1.4.4
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rhash/}
GITHUB_PROJECT=	RHash
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rhash/RHash
COMMENT=	Calculate/check CRC32, MD5, SHA1, GOST, TTH, BTIH or other hash sums
LICENSE=	mit

WRKSRC=			${WRKDIR}/${DISTNAME:S/rh/RH/}
HAS_CONFIGURE=		yes
USE_GCC_RUNTIME=	yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--disable-gettext
CONFIGURE_ARGS+=	--disable-symlinks
CONFIGURE_ARGS+=	--enable-lib-shared
CONFIGURE_ARGS+=	--enable-lib-static
CONFIGURE_ARGS+=	--enable-openssl
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--extra-cflags=-I${BUILDLINK_PREFIX.openssl}/include
CONFIGURE_ARGS+=	--extra-ldflags=-L${BUILDLINK_PREFIX.openssl}/lib\ ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib\ ${LDFLAGS:Q}
INSTALL_TARGET=		build-install-binary install-man
INSTALL_TARGET+=	install-pkg-config install-lib-shared
INSTALL_TARGET+=	install-lib-headers
INSTALLATION_DIRS=	share/examples/rhash

USE_LIBTOOL=		yes
BUILD_TARGET+=		librhash/librhash.la rhash
TEST_TARGET=		test

MAKE_FLAGS+=		LIBRHASH_SHARED=librhash/librhash.la
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}

.include "../../mk/bsd.prefs.mk"

# posix_memalign
.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 100600
LDFLAGS+=	-lMacportsLegacySupport
.  include "../../devel/macports-legacy-support/buildlink3.mk"
.endif

LDFLAGS+=	-lcrypto

PKGCONFIG_OVERRIDE=		dist/librhash.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

CONF_FILES+=	${PREFIX}/share/examples/rhash/rhashrc ${PKG_SYSCONFDIR}/rhashrc

post-install:
	${INSTALL_DATA} ${WRKSRC}/dist/rhashrc.sample \
		${DESTDIR}${PREFIX}/share/examples/rhash/rhashrc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
