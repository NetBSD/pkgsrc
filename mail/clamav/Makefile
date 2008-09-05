# $NetBSD: Makefile,v 1.86.4.1 2008/09/05 11:41:53 ghen Exp $

DISTNAME=	clamav-${CLAMAV_VERSION}
PKGNAME=	clamav-${CLAMAV_VERSION:S/-/./}
#PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clamav/}

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.clamav.net/
COMMENT=	Anti-virus toolkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CLAMAV_VERSION=		0.94

USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-clamav
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-dbdir=${CLAMAV_DBDIR}
CONFIGURE_ARGS+=	--with-uid=${CLAMAV_USER}
CONFIGURE_ARGS+=	--with-group=${CLAMAV_GROUP}
CONFIGURE_ARGS+=	--with-tcpwrappers
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M1.*)
CONFIGURE_ARGS+=	--disable-readdir-r
.else
CONFIGURE_ARGS+=	--enable-readdir_r
.endif

BUILD_DEFS+=	CLAMAV_USER CLAMAV_GROUP CLAMAV_DBDIR
FILES_SUBST+=	CLAMAV_USER=${CLAMAV_USER}
MESSAGE_SUBST+=	CLAMAV_USER=${CLAMAV_USER}

RCD_SCRIPTS=	clamd freshclamd
PKG_GROUPS+=	${CLAMAV_GROUP}
PKG_USERS+=	${CLAMAV_USER}:${CLAMAV_GROUP}

PKG_GROUPS_VARS+=	CLAMAV_GROUP
PKG_USERS_VARS=		CLAMAV_USER

EGDIR=		${PREFIX}/share/examples/clamav
FILES_SUBST+=	CLAMAV_DBDIR=${CLAMAV_DBDIR}

OWN_DIRS_PERMS=		${CLAMAV_DBDIR} ${CLAMAV_USER} ${CLAMAV_GROUP} 0775
CONF_FILES=		# empty
CONF_FILES_PERMS=	# empty
.for i in clamd.conf freshclam.conf
CONF_FILES+=		${EGDIR}/${i} ${PKG_SYSCONFDIR}/${i}
.endfor
.for i in daily.cvd main.cvd
CONF_FILES_PERMS+=	${EGDIR}/${i} ${CLAMAV_DBDIR}/${i}	\
			${CLAMAV_USER} ${CLAMAV_GROUP} 0664
.endfor

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} CFGINST=${EGDIR} DBINST=${EGDIR}

.include "options.mk"

# pkgsrc enforces a "secure" version of zlib, so don't let this check
# bomb the build.
CONFIGURE_ARGS+=	--disable-zlib-vcheck

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
