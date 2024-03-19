# $NetBSD: Makefile,v 1.91 2024/03/19 02:16:57 nia Exp $

DISTNAME=	memcached-1.6.23
CATEGORIES=	devel
MASTER_SITES=	https://memcached.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://memcached.org/
COMMENT=	High-performance distributed memory object caching system
LICENSE=	2-clause-bsd

USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-coverage # coverage fails on some platforms
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}

REPLACE_PERL=		scripts/memcached-tool
RCD_SCRIPTS=		memcached
INSTALLATION_DIRS=	share/doc/${PKGBASE}

.include "../../mk/bsd.prefs.mk"

# Macs lacked clock_gettime way past its implement-by date.
.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 101200
LDFLAGS+=	-lMacportsLegacySupport
.  include "../../devel/macports-legacy-support/buildlink3.mk"
.endif

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_FILES.rpath+=	configure
SUBST_SED.rpath+=	-e 's|-Wl,-rpath,|${COMPILER_RPATH_FLAG}|g'

.include "options.mk"

BUILD_DEFS+=		VARBASE

MEMCACHED_USER?=	memcached
MEMCACHED_GROUP?=	memcached
MEMCACHED_HOME?=	${VARBASE}/chroot/${PKGBASE}

PKG_GROUPS=			${MEMCACHED_GROUP}
PKG_USERS=			${MEMCACHED_USER}:${MEMCACHED_GROUP}
PKG_GROUPS_VARS+=		MEMCACHED_GROUP
PKG_USERS_VARS=			MEMCACHED_USER
PKG_HOME.${MEMCACHED_USER}=	${MEMCACHED_HOME}
PKG_GECOS.${MEMCACHED_USER}=	Memcached

OWN_DIRS_PERMS+=	${MEMCACHED_HOME} ${MEMCACHED_USER} ${MEMCACHED_GROUP} 0700
FILES_SUBST+=		MEMCACHED_USER=${MEMCACHED_USER}
FILES_SUBST+=		MEMCACHED_GROUP=${MEMCACHED_GROUP} MEMCACHED_HOME=${MEMCACHED_HOME}
MESSAGE_SUBST+=		MEMCACHED_HOME=${MEMCACHED_HOME}

TEST_TARGET=		test

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/memcached-tool ${DESTDIR}${PREFIX}/bin

.include "../../devel/libevent/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=1.0
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
