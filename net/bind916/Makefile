# $NetBSD: Makefile,v 1.35 2022/01/27 13:35:36 taca Exp $

DISTNAME=	bind-${BIND_VERSION}
PKGNAME=	${DISTNAME:S/-P/pl/}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/${BIND_VERSION}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.isc.org/software/bind/
COMMENT=	Berkeley Internet Name Daemon implementation of DNS, version 9.16
LICENSE=	mpl-2.0

CONFLICTS+=	host-[0-9]*

MAKE_JOBS_SAFE=	no

BIND_VERSION=	9.16.25

BUILD_DEFS+=	BIND_DIR VARBASE

.include "options.mk"

USE_TOOLS+=		autoconf pax perl pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CHECK_FILES_SKIP=	bin/tests/system/system-test-driver.sh
MAKE_ENV+=		WRKDIR=${WRKDIR} PREFIX=${PREFIX}

.if ${OPSYS} == "Linux" && !exists(/usr/include/sys/capability.h)
CONFIGURE_ARGS+=		--disable-linux-caps
.endif

CONFIGURE_ARGS+=		--with-libtool
CONFIGURE_ARGS+=		--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=		--localstatedir=${VARBASE}
CONFIGURE_ARGS+=		--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=		--with-python=no
CONFIGURE_ARGS.DragonFly+=	--disable-kqueue
CONFIGURE_ARGS.SunOS+=		--disable-epoll

BUILDLINK_TRANSFORM.SunOS+=	rm:-zrelax=transtls

PKG_GROUPS_VARS+=	BIND_GROUP
PKG_USERS_VARS=		BIND_USER

PKG_GROUPS=		${BIND_GROUP}
PKG_USERS=		${BIND_USER}:${BIND_GROUP}

PKG_GECOS.${BIND_USER}=	Named pseudo-user
PKG_HOME.${BIND_USER}=	${BIND_DIR}

DOCS=			CHANGES HISTORY OPTIONS README

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
	cd ${WRKSRC} && autoconf -f

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../mk/atomic64.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
