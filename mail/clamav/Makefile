# $NetBSD: Makefile,v 1.37 2005/05/05 00:42:56 xtraeme Exp $

DISTNAME=	clamav-${CLAMAV_VERSION}
PKGNAME=	clamav-${CLAMAV_VERSION:S/-/./}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clamav/}

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.clamav.net/
COMMENT=	Anti-virus toolkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CLAMAV_VERSION=		0.84

USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-clamav
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-dbdir=${VIRUSDBDIR}
CONFIGURE_ARGS+=	--with-uid=${CLAMAV_USER}
CONFIGURE_ARGS+=	--with-group=${CLAMAV_GROUP}
CONFIGURE_ARGS+=	--with-tcpwrappers

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	CLAMAV_USER CLAMAV_GROUP
FILES_SUBST+=	CLAMAV_USER=${CLAMAV_USER}
MESSAGE_SUBST+=	CLAMAV_USER=${CLAMAV_USER}

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL

RCD_SCRIPTS=	clamd freshclamd
PKG_GROUPS+=	${CLAMAV_GROUP}
PKG_USERS+=	${CLAMAV_USER}:${CLAMAV_GROUP}::Clamav\\ User

VIRUSDBDIR=	${VARBASE}/clamav
EGDIR=		${PREFIX}/share/examples/clamav
FILES_SUBST+=	VIRUSDBDIR=${VIRUSDBDIR}

OWN_DIRS_PERMS=		${VIRUSDBDIR} ${CLAMAV_USER} ${CLAMAV_GROUP} 0775
CONF_FILES=		# empty
CONF_FILES_PERMS=	# empty
.for _file_ in clamd.conf freshclam.conf
CONF_FILES+=		${EGDIR}/${_file_} ${PKG_SYSCONFDIR}/${_file_}
.endfor
.for _file_ in daily.cvd main.cvd
CONF_FILES_PERMS+=	${EGDIR}/${_file_} ${VIRUSDBDIR}/${_file_}	\
			${CLAMAV_USER} ${CLAMAV_GROUP} 0664
.endfor
.undef _file_

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} CFGINST=${EGDIR} DBINST=${EGDIR}

PKG_DEFAULT_OPTIONS+=	curl

.if defined(USE_MILTER) && !empty(USE_MILTER:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	milter
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.clamav
PKG_SUPPORTED_OPTIONS=	curl milter
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmilter)
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
BUILDLINK_DEPENDS.curl+=curl>=7.10.0
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
