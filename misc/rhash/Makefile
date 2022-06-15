# $NetBSD: Makefile,v 1.20 2022/06/15 08:54:58 adam Exp $

DISTNAME=	rhash-1.4.3
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
CONFIGURE_ARGS+=	--disable-symlinks
CONFIGURE_ARGS+=	--enable-lib-shared
CONFIGURE_ARGS+=	--enable-lib-static
CONFIGURE_ARGS+=	--enable-openssl
CONFIGURE_ARGS+=	--extra-cflags=-I${PREFIX}/include\ ${CFLAGS:Q}
CONFIGURE_ARGS+=	--extra-ldflags=-L${PREFIX}/lib\ -Wl,-R${PREFIX}/lib\ ${LDFLAGS:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INSTALL_TARGET=		install install-pkg-config install-lib-so-link
INSTALLATION_DIRS=	share/examples/rhash
TEST_TARGET=		test

PKGCONFIG_OVERRIDE=		dist/librhash.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

CONF_FILES+=	${PREFIX}/share/examples/rhash/rhashrc ${PKG_SYSCONFDIR}/rhashrc

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/rhashrc ${DESTDIR}${PREFIX}/share/examples/rhash/rhashrc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
