# $NetBSD: Makefile,v 1.25 2004/10/03 00:12:52 tv Exp $

DISTNAME=	clamav-${CLAMAV_VERSION}
PKGNAME=	clamav-${CLAMAV_VERSION:S/-/./}
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clamav/}

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.clamav.net/
COMMENT=	Anti-virus toolkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CLAMAV_VERSION=		0.75.1

USE_BUILDLINK3=		yes
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

RCD_SCRIPTS=	clamd
PKG_GROUPS+=    ${CLAMAV_GROUP}
PKG_USERS+=     ${CLAMAV_USER}:${CLAMAV_GROUP}::Clamav\\ User

VIRUSDBDIR=	${VARBASE}/clamav
EGDIR=		${PREFIX}/share/examples/clamav
FILES_SUBST+=	VIRUSDBDIR=${VIRUSDBDIR}

OWN_DIRS_PERMS=		${VIRUSDBDIR} ${CLAMAV_USER} ${CLAMAV_GROUP} 0775
CONF_FILES=		# empty
CONF_FILES_PERMS=	# empty
.for _file_ in clamav.conf freshclam.conf
CONF_FILES+=		${EGDIR}/${_file_} ${PKG_SYSCONFDIR}/${_file_}
.endfor
.for _file_ in daily.cvd main.cvd
CONF_FILES_PERMS+=	${EGDIR}/${_file_} ${VIRUSDBDIR}/${_file_}	\
			${CLAMAV_USER} ${CLAMAV_GROUP} 0664
.endfor
.undef _file_

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} CFGINST=${EGDIR} DBINST=${EGDIR}

.if defined(USE_MILTER) && !empty(USE_MILTER:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	milter
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.clamav
PKG_SUPPORTED_OPTIONS=	milter
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

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
