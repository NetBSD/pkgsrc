# $NetBSD: Makefile,v 1.58 2026/04/24 17:10:41 wiz Exp $

DISTNAME=	pdns-recursor-5.4.1
PKGNAME=	${DISTNAME:S/pdns/powerdns/}
CATEGORIES=	net
MASTER_SITES=	https://downloads.powerdns.com/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://www.powerdns.com/
COMMENT=	PowerDNS resolver/recursing nameserver
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-libsodium
CONFIGURE_ARGS+=	--enable-dns-over-tls
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-headers}

CHECK_WRKREF_SKIP+=	sbin/pdns_recursor

EGDIR=			${PREFIX}/share/examples/powerdns-recursor
CONF_FILES=		${EGDIR}/recursor.yml-dist ${PKG_SYSCONFDIR}/recursor.yml
INSTALLATION_DIRS+=	${EGDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

RCD_SCRIPTS=		pdns_recursor

SMF_NAME=		pdns-recursor
SMF_METHODS=		pdns_recursor

do-build:
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} ${BUILD_TARGET}

.include "cargo-depends.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../net/fstrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
