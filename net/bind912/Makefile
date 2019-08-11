# $NetBSD: Makefile,v 1.14 2019/08/11 13:22:06 wiz Exp $

DISTNAME=	bind-${BIND_VERSION}
PKGNAME=	${DISTNAME:S/-P/pl/}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/${BIND_VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.isc.org/software/bind/
COMMENT=	Berkeley Internet Name Daemon implementation of DNS, version 9.12
LICENSE=	mpl-2.0

CONFLICTS+=	host-[0-9]*

MAKE_JOBS_SAFE=	no
USE_CWRAPPERS=	no

BIND_VERSION=	9.12.4-P2

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	BIND_DIR VARBASE

.include "options.mk"

USE_TOOLS+=		pax perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-libtool
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-python=no
.if !empty(MACHINE_PLATFORM:MNetBSD-*-m68k) || \
    !empty(MACHINE_PLATFORM:MNetBSD-*-mipsel) || \
    !empty(MACHINE_PLATFORM:MNetBSD-*-vax)
CONFIGURE_ARGS+=	--disable-atomic
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-powerpc} != ""
CONFIGURE_ARGS+=	--disable-threads
.endif
CONFIGURE_ARGS.DragonFly+=	--disable-kqueue

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

INSTALLATION_DIRS+=	${DOCDIR} ${DOCDIR}/arm

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/arm/*.html ${DESTDIR}${PREFIX}/${DOCDIR}/arm

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
