# $NetBSD: Makefile,v 1.113.2.1 2006/10/07 02:47:03 salo Exp $
#
# The CUPS author is very good about taking back changes into the main
# CUPS distribution.  The correct place to send patches or bug-fixes is:
# cups-bugs@cups.org.

DISTNAME=	cups-${DIST_VERS}-source
PKGNAME=	cups-${VERS}
PKGREVISION=	11
BASE_VERS=	1.1.23
DIST_VERS=	${BASE_VERS}
VERS=		${DIST_VERS:S/-/./g}
CATEGORIES=	print
MASTER_SITES=	http://ftp.easysw.com/pub/cups/${BASE_VERS}/ \
		ftp://ftp2.easysw.com/pub/cups/${BASE_VERS}/ \
		ftp://ftp3.easysw.com/pub/cups/${BASE_VERS}/ \
		ftp://ftp.ntua.gr/pub/gnu/cups/${BASE_VERS}/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/cups/${BASE_VERS}/ \
		ftp://ftp.mpg.goe.ni.schule.de/pub/internet/printing/cups/${BASE_VERS}/ \
		ftp://ftp.fisek.com.tr/pub/cups/${BASE_VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://www.cups.org/
COMMENT=	Common UNIX Printing System

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
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/cups
CONFIGURE_ARGS+=	--with-serverbindir=${PREFIX}/libexec/cups
CONFIGURE_ARGS+=	--with-rcdir=${RCD_SCRIPTS_DIR:Q}
CONFIGURE_ARGS+=	--with-cups-user=${CUPS_USER:Q}
CONFIGURE_ARGS+=	--with-cups-group=${CUPS_GROUP:Q}
CONFIGURE_ARGS+=	--with-manext=bsd
CONFIGURE_ARGS+=	--enable-libtool
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ENV+=		DSOFLAGS=${LDFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.cups
PKG_SUPPORTED_OPTIONS=	pam slp
PKG_SUGGESTED_OPTIONS=	slp
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pam
MESSAGE_SRC=		${PKGDIR}/MESSAGE
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.pam
PLIST_SUBST+=		PAM=
.else
CONFIGURE_ARGS+=	--disable-pam
MESSAGE_SRC=		${.CURDIR}/MESSAGE
PLIST_SUBST+=		PAM="@comment "
.endif

.if !empty(PKG_OPTIONS:Mslp)
.include "../../net/openslp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-slp
.else
CONFIGURE_ARGS+=	--disable-slp
.endif

# CUPS_USER	username of the CUPS administrator
# CUPS_GROUP	group of the CUPS administrator
#
CUPS_USER?=		lp
CUPS_GROUP?=		sys
FILES_SUBST+=		CUPS_USER=${CUPS_USER:Q}
FILES_SUBST+=		CUPS_GROUP=${CUPS_GROUP:Q}

BUILD_DEFS+=		CUPS_USER CUPS_GROUP

DOCDIR=			${PREFIX}/share/doc/cups
EGDIR=			${PREFIX}/share/examples/cups
PKG_SYSCONFSUBDIR=	cups
CUPS_CONFDIR=		${PKG_SYSCONFDIR}
CUPS_LOGDIR=		/var/log/cups
CUPS_REQUESTS=		/var/spool/cups

PKG_GROUPS=		${CUPS_GROUP}
PKG_USERS=		${CUPS_USER}:${CUPS_GROUP}
PKG_GECOS.${CUPS_USER}=	Common UNIX Printing System user
PKG_SHELL.${CUPS_USER}=	${SH}

SPECIAL_PERMS=		${PREFIX}/bin/lppasswd ${CUPS_USER} ${CUPS_GROUP} 4755
CONF_FILES=		${EGDIR}/client.conf ${CUPS_CONFDIR}/client.conf
CONF_FILES+=		${EGDIR}/cupsd.conf ${CUPS_CONFDIR}/cupsd.conf
CONF_FILES+=		${EGDIR}/classes.conf ${CUPS_CONFDIR}/classes.conf
CONF_FILES+=		${EGDIR}/mime.convs ${CUPS_CONFDIR}/mime.convs
CONF_FILES+=		${EGDIR}/mime.types ${CUPS_CONFDIR}/mime.types
CONF_FILES+=		${EGDIR}/printers.conf ${CUPS_CONFDIR}/printers.conf
RCD_SCRIPTS=		cupsd

OWN_DIRS=		${CUPS_CONFDIR}
OWN_DIRS+=		${CUPS_CONFDIR}/interfaces
OWN_DIRS+=		${CUPS_CONFDIR}/ppd
OWN_DIRS+=		${CUPS_LOGDIR}
OWN_DIRS_PERMS=		${CUPS_CONFDIR}/certs ${CUPS_USER} ${CUPS_GROUP} 0711
OWN_DIRS_PERMS+=	${CUPS_REQUESTS} ${CUPS_USER} ${CUPS_GROUP} 0710
OWN_DIRS_PERMS+=	${CUPS_REQUESTS}/tmp ${CUPS_USER} ${CUPS_GROUP} 1770

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/cups.pam
SUBST_SED.paths+=	-e 's,@LOCALBASE@,${LOCALBASE},g'
SUBST_STAGE.paths=	post-patch

pre-configure:
	cd ${WRKSRC} && aclocal && autoconf

post-extract:
	${CP} ${FILESDIR}/cups.pam ${WRKDIR}/cups.pam

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in CGI.txt ENCRYPTION.txt LICENSE.txt README.txt; do	\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR}/$${file};	\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/conf; for file in *.conf mime.*; do		\
		case $${file} in					\
		pam.conf)						\
			;;						\
		*)							\
			${INSTALL_DATA} $${file} ${EGDIR}/$${file};	\
			;;						\
		esac;							\
	done
.if !empty(PKG_OPTIONS:Mpam)
	${INSTALL_DATA} ${WRKDIR}/cups.pam ${EGDIR}
.endif

.include "../../mk/bsd.pkg.mk"
