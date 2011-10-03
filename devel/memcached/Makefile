# $NetBSD: Makefile,v 1.25 2011/10/03 11:53:11 adam Exp $

DISTNAME=	memcached-1.4.7
CATEGORIES=	devel
MASTER_SITES=	http://memcached.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.memcached.org/
COMMENT=	High-performance distributed memory object caching system
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}

REPLACE_PERL=		scripts/memcached-tool
RCD_SCRIPTS=		memcached
INSTALLATION_DIRS=	share/doc/${PKGBASE} share/examples/rc.d

.include "../../mk/bsd.prefs.mk"

MEMCACHED_USER?=	memcached
MEMCACHED_GROUP?=	memcached
PKG_GROUPS=		${MEMCACHED_GROUP}
PKG_USERS=		${MEMCACHED_USER}:${MEMCACHED_GROUP}
PKG_GROUPS_VARS+=	MEMCACHED_GROUP
PKG_USERS_VARS+=	MEMCACHED_USER
FILES_SUBST+=		MEMCACHED_USER=${MEMCACHED_USER}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/memcached-tool ${DESTDIR}${PREFIX}/bin

.include "../../devel/libevent/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=1.0
.include "../../mk/bsd.pkg.mk"
