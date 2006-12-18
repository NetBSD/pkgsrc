# $NetBSD: Makefile,v 1.61.2.3 2006/12/18 12:37:34 salo Exp $

DISTNAME=	clamav-${CLAMAV_VERSION}
PKGNAME=	clamav-${CLAMAV_VERSION:S/-/./}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clamav/}

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.clamav.net/
COMMENT=	Anti-virus toolkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CLAMAV_VERSION=		0.88.7
#PKGREVISION=		1

USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-clamav
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-dbdir=${VIRUSDBDIR:Q}
CONFIGURE_ARGS+=	--with-uid=${CLAMAV_USER:Q}
CONFIGURE_ARGS+=	--with-group=${CLAMAV_GROUP:Q}
CONFIGURE_ARGS+=	--with-tcpwrappers
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
# the following was added only on the pkgsrc-2006Q3 branch to keep
# the behaviour of the package compatible with the 0.88.4 version.
CONFIGURE_ARGS+=	--enable-no-cache

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	CLAMAV_USER CLAMAV_GROUP
FILES_SUBST+=	CLAMAV_USER=${CLAMAV_USER:Q}
MESSAGE_SUBST+=	CLAMAV_USER=${CLAMAV_USER}

RCD_SCRIPTS=	clamd freshclamd
PKG_GROUPS+=	${CLAMAV_GROUP}
PKG_USERS+=	${CLAMAV_USER}:${CLAMAV_GROUP}

VIRUSDBDIR=	${VARBASE}/clamav
EGDIR=		${PREFIX}/share/examples/clamav
FILES_SUBST+=	VIRUSDBDIR=${VIRUSDBDIR:Q}

OWN_DIRS_PERMS=		${VIRUSDBDIR} ${CLAMAV_USER} ${CLAMAV_GROUP} 0775
CONF_FILES=		# empty
CONF_FILES_PERMS=	# empty
.for i in clamd.conf freshclam.conf
CONF_FILES+=		${EGDIR}/${i} ${PKG_SYSCONFDIR}/${i}
.endfor
.for i in daily.cvd main.cvd
CONF_FILES_PERMS+=	${EGDIR}/${i} ${VIRUSDBDIR}/${i}	\
			${CLAMAV_USER} ${CLAMAV_GROUP} 0664
.endfor

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} CFGINST=${EGDIR} DBINST=${EGDIR}

PKG_OPTIONS_VAR=	PKG_OPTIONS.clamav
PKG_SUPPORTED_OPTIONS=	curl milter
PKG_SUGGESTED_OPTIONS=	curl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmilter)
# force use of pkgsrc version of libmilter -- clamav uses the sendmail binary
# to check API compatibility(!), so it must build with as new a version of
# libmilter as pkgsrc is capable of providing
USE_BUILTIN.libmilter=	no
.  include "../../mail/libmilter/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-milter
PLIST_SUBST+=		MILTER=
.else
CONFIGURE_ARGS+=	--disable-milter
# XXX --disable-milter doesn't work as expected, so we need this
CONFIGURE_ENV+=		ac_cv_header_libmilter_mfapi_h=no
PLIST_SUBST+=		MILTER="@comment "
.endif

.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libcurl
BUILDLINK_API_DEPENDS.curl+=curl>=7.10.0
.else
CONFIGURE_ARGS+=	--without-libcurl
.endif

# pkgsrc enforces a "secure" version of zlib, so don't let this check
# bomb the build.
CONFIGURE_ARGS+=	--disable-zlib-vcheck

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
