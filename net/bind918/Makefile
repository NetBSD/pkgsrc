# $NetBSD: Makefile,v 1.32 2024/05/16 15:24:13 taca Exp $

DISTNAME=	bind-${BIND_VERSION}
PKGNAME=	${DISTNAME:S/-P/pl/}
CATEGORIES=	net
MASTER_SITES=	https://downloads.isc.org/isc/bind9/${BIND_VERSION}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	sekiya@NetBSD.org
HOMEPAGE=	https://www.isc.org/bind/
COMMENT=	Berkeley Internet Name Daemon implementation of DNS, version 9.18
LICENSE=	mpl-2.0

CONFLICTS+=	host-[0-9]*

MAKE_JOBS_SAFE=	no

BIND_VERSION=	9.18.27

BUILD_DEFS+=	BIND_DIR VARBASE

.include "options.mk"

USE_TOOLS+=		aclocal autoconf automake pax perl pkg-config
USE_LIBTOOL=		yes
# Requires support for C11 atomics.
USE_CC_FEATURES+=	c11
GNU_CONFIGURE=		yes
CHECK_FILES_SKIP=	bin/tests/system/system-test-driver.sh
MAKE_ENV+=		WRKDIR=${WRKDIR} PREFIX=${PREFIX}

.if ${OPSYS} == "Linux" && !exists(/usr/include/sys/capability.h)
CONFIGURE_ARGS+=		--disable-linux-caps
.endif

CONFIGURE_ARGS+=		--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=		--localstatedir=${VARBASE}
CONFIGURE_ARGS+=		--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS.DragonFly+=	--disable-kqueue
CONFIGURE_ARGS.SunOS+=		--disable-epoll

# Remove WRKDIR reference by modifying pkg-config related path.
SUBST_CLASSES+=		pkgconf
SUBST_STAGE.pkgconf=	pre-configure
SUBST_FILES.pkgconf=	configure.ac
SUBST_MESSAGE.pkgconf=	Fixing pkg-config path.
SUBST_VARS.pkgconf+=	BUILDLINK_DIR PREFIX TOOLS_DIR

BUILDLINK_TRANSFORM.SunOS+=	rm:-zrelax=transtls

PKG_GROUPS_VARS+=	BIND_GROUP
PKG_USERS_VARS=		BIND_USER

PKG_GROUPS=		${BIND_GROUP}
PKG_USERS=		${BIND_USER}:${BIND_GROUP}

PKG_GECOS.${BIND_USER}=	Named pseudo-user
PKG_HOME.${BIND_USER}=	${BIND_DIR}

DOCS=			CHANGES OPTIONS.md README.md

FILES_SUBST+=		BIND_GROUP=${BIND_GROUP} \
			BIND_USER=${BIND_USER} PAX=${PAX:Q} \
			SSLBASE=${SSLBASE}
MESSAGE_SUBST+=		BIND_DIR=${BIND_DIR} BIND_USER=${BIND_USER}

DOCDIR=			share/doc/bind9

RCD_SCRIPTS=		named9
SMF_METHODS=		named

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/bind9
CONF_FILES+=		share/examples/bind9/bind.keys \
			${PKG_SYSCONFDIR}/bind.keys

INSTALLATION_DIRS+=	${DOCDIR}

pre-configure:
	cd ${WRKSRC} && \
	rm -rf autom4te*.cache && \
	aclocal && \
	automake --include-deps --add-missing --copy && \
	autoconf -f

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../mk/atomic64.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
