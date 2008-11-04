# $NetBSD: Makefile,v 1.135.4.1 2008/11/04 12:25:43 rtr Exp $
#
# The CUPS author is very good about taking back changes into the main
# CUPS distribution.  The correct place to send patches or bug-fixes is:
# cups-bugs@cups.org.

DISTNAME=	cups-${DIST_VERS}-source
PKGNAME=	cups-${VERS}
BASE_VERS=	1.3.9
DIST_VERS=	${BASE_VERS}
VERS=		${DIST_VERS:S/-/./g}
CATEGORIES=	print
MASTER_SITES=	http://ftp.easysw.com/pub/cups/${BASE_VERS}/ \
		ftp://ftp.ntua.gr/pub/gnu/cups/${BASE_VERS}/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/cups/${BASE_VERS}/ \
		ftp://ftp.fisek.com.tr/pub/cups/${BASE_VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://www.cups.org/
COMMENT=	Common UNIX Printing System

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	LPRng-[0-9]* LPRng-core-[0-9]*

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/cups-${BASE_VERS}
UNLIMIT_RESOURCES=	datasize memorysize
USE_LANGUAGES=		c c++	# pdftops is a C++ application
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf automake gmake
USE_LIBTOOL=		yes
INSTALL_TARGET=		installcups
# patch-a[jkl] were added for 2.60
AUTOCONF_REQD=		2.60

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-cachedir=${VARBASE:Q}/cache/cups
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/cups
CONFIGURE_ARGS+=	--with-serverbindir=${PREFIX}/libexec/cups
CONFIGURE_ARGS+=	--with-rcdir=${RCD_SCRIPTS_DIR:Q}
CONFIGURE_ARGS+=	--with-cups-user=${CUPS_USER:Q}
CONFIGURE_ARGS+=	--with-cups-group=${CUPS_GROUP:Q}
CONFIGURE_ARGS+=	--with-manext=bsd
CONFIGURE_ARGS+=	--without-perl
CONFIGURE_ARGS+=	--without-icondir
CONFIGURE_ARGS+=	--without-menudir
CONFIGURE_ARGS+=	--enable-libtool
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-gnutls=no
CONFIGURE_ARGS+=	--enable-openssl
CONFIGURE_ARGS+=	--without-php

CONFIGURE_ENV+=		DSOFLAGS=${LDFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

# CUPS_USER	username of the CUPS administrator
# CUPS_GROUP	group of the CUPS administrator
#
CUPS_USER?=		lp
CUPS_GROUP?=		sys
FILES_SUBST+=		CUPS_USER=${CUPS_USER:Q}
FILES_SUBST+=		CUPS_GROUP=${CUPS_GROUP:Q}

PKG_GROUPS_VARS+=	CUPS_GROUP
PKG_USERS_VARS+=	CUPS_USER

BUILD_DEFS+=		VARBASE

DOCDIR=			${PREFIX}/share/doc/cups
EGDIR=			${PREFIX}/share/examples/cups
PKG_SYSCONFSUBDIR=	cups
CUPS_CONFDIR=		${PKG_SYSCONFDIR}
CUPS_LOGDIR=		${VARBASE}/log/cups
CUPS_REQUESTS=		${VARBASE}/spool/cups

PKG_GROUPS=		${CUPS_GROUP}
PKG_USERS=		${CUPS_USER}:${CUPS_GROUP}
PKG_GECOS.${CUPS_USER}=	Common UNIX Printing System user
PKG_SHELL.${CUPS_USER}=	${SH}

SPECIAL_PERMS=		${PREFIX}/bin/lppasswd ${CUPS_USER} ${CUPS_GROUP} 4555
CONF_FILES=		${EGDIR}/cupsd.conf ${CUPS_CONFDIR}/cupsd.conf
CONF_FILES+=		${EGDIR}/mime.convs ${CUPS_CONFDIR}/mime.convs
CONF_FILES+=		${EGDIR}/mime.types ${CUPS_CONFDIR}/mime.types
RCD_SCRIPTS=		cupsd

OWN_DIRS=		${CUPS_CONFDIR}
OWN_DIRS+=		${CUPS_CONFDIR}/interfaces
OWN_DIRS+=		${CUPS_CONFDIR}/ppd
OWN_DIRS+=		${PREFIX}/libexec/cups/driver
OWN_DIRS+=		${CUPS_LOGDIR}
OWN_DIRS_PERMS=		${CUPS_CONFDIR}/certs ${CUPS_USER} ${CUPS_GROUP} 0711
OWN_DIRS_PERMS+=	${CUPS_CONFDIR}/ssl ${CUPS_USER} ${CUPS_GROUP} 0700
OWN_DIRS_PERMS+=	${CUPS_REQUESTS} ${CUPS_USER} ${CUPS_GROUP} 0710
OWN_DIRS_PERMS+=	${CUPS_REQUESTS}/tmp ${CUPS_USER} ${CUPS_GROUP} 1770
OWN_DIRS_PERMS+=	${VARBASE}/cache/cups ${CUPS_USER} ${CUPS_GROUP} 0775

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/cups.pam
SUBST_SED.paths+=	-e 's,@LOCALBASE@,${LOCALBASE},g'
SUBST_STAGE.paths=	post-patch

SUBST_CLASSES+=		rpathfix
SUBST_FILES.rpathfix=	cups-config.in
SUBST_MESSAGE.rpathfix=	Adding rpath to cups-config.
SUBST_SED.rpathfix=	-e 's|@EXPORT_LDFLAGS@|${COMPILER_RPATH_FLAG}${LOCALBASE}/lib|g'
SUBST_STAGE.rpathfix=	post-patch

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}
INSTALL_ENV+=		DSTROOT=${DESTDIR:Q}

pre-configure:
	cd ${WRKSRC} && aclocal && autoconf

post-extract:
	${CP} ${FILESDIR}/cups.pam ${WRKDIR}/cups.pam

post-install:
	for file in LICENSE.txt README.txt; do				\
		${INSTALL_DATA} ${WRKSRC}/$${file}			\
		     ${DESTDIR}${DOCDIR}/$${file}; \
	done
	cd ${WRKSRC}/conf; for file in *.conf mime.convs mime.types; do	\
		case $${file} in					\
		pam.conf)						\
			;;						\
		*)							\
			${INSTALL_DATA} $${file} 			\
			    ${DESTDIR}${EGDIR}/$${file};		\
			;;						\
		esac;							\
	done
.if !empty(PKG_OPTIONS:Mpam)
	${INSTALL_DATA} ${WRKDIR}/cups.pam ${DESTDIR}${EGDIR}
.endif

.include "../../mk/bsd.pkg.mk"
