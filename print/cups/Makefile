# $NetBSD: Makefile,v 1.54 2002/10/20 23:33:42 jlam Exp $
#
# The CUPS author is very good about taking back changes into the main
# CUPS distribution.  The correct place to send patches or bug-fixes is:
# cups-bugs@cups.org.

DISTNAME=		cups-${DIST_VERS}-source
PKGNAME=		cups-${VERS}
BASE_VERS=		1.1.16
DIST_VERS=		${BASE_VERS}
VERS=			${DIST_VERS:S/-/./g}
WRKSRC=			${WRKDIR}/cups-${BASE_VERS}
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.easysw.com/pub/cups/${BASE_VERS}/ \
			ftp://ftp2.easysw.com/pub/cups/${BASE_VERS}/ \
			ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/cups/${BASE_VERS}/ \
			ftp://ftp.mpg.goe.ni.schule.de/pub/internet/printing/cups/${BASE_VERS}/ \
			ftp://ftp.ntua.gr/pub/gnu/cups/${BASE_VERS}/ \
			ftp://ftp.fisek.com.tr/pub/cups/${BASE_VERS}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.cups.org/
COMMENT=		Common UNIX Printing System

CONFLICTS+=		LPRng-[0-9]* LPRng-core-[0-9]*

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
GNU_CONFIGURE=		# defined
UNLIMIT_RESOURCES=	datasize memorysize
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/html/cups
CONFIGURE_ARGS+=	--with-cups-user=${CUPS_USER}
CONFIGURE_ARGS+=	--with-cups-group=${CUPS_GROUP}
CONFIGURE_ARGS+=	--enable-libtool-unsupported="${PKGLIBTOOL}"
CONFIGURE_ARGS+=	--enable-slp
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ENV+=		DSOFLAGS="${LDFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if defined(USE_PAM)
.  include "../../security/PAM/buildlink2.mk"
BUILD_DEFS+=		USE_PAM
CONFIGURE_ARGS+=	--enable-pam
PLIST_SRC=		${PKGDIR}/PLIST.pam
PLIST_SRC+=		${PKGDIR}/PLIST
MESSAGE_SRC=		${PKGDIR}/MESSAGE
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.pam
.else
CONFIGURE_ARGS+=	--disable-pam
MESSAGE_SRC=		${.CURDIR}/MESSAGE
PLIST_SRC=		${PKGDIR}/PLIST
.endif

# CUPS_USER	username of the CUPS administrator
# CUPS_GROUP	group of the CUPS administrator
#
CUPS_USER?=		lp
CUPS_GROUP?=		sys
FILES_SUBST+=		CUPS_USER=${CUPS_USER}
FILES_SUBST+=		CUPS_GROUP=${CUPS_GROUP}

BUILD_DEFS+=		CUPS_USER CUPS_GROUP

DOCDIR=			${PREFIX}/share/doc/cups
EGDIR=			${PREFIX}/share/examples/cups
PKG_SYSCONFSUBDIR=	cups
CUPS_CONFDIR=		${PKG_SYSCONFDIR}
CUPS_LOGDIR=		/var/log/cups
CUPS_REQUESTS=		/var/spool/cups

PKG_GROUPS=		${CUPS_GROUP}
PKG_USERS=		${CUPS_USER}:${CUPS_GROUP}::Common\\ UNIX\\ Printing\\ System\\ user::${SH}

SPECIAL_PERMS=		${PREFIX}/bin/lppasswd ${CUPS_USER} ${CUPS_GROUP} 4755
CONF_FILES=		${EGDIR}/client.conf ${CUPS_CONFDIR}/client.conf
CONF_FILES+=		${EGDIR}/cupsd.conf ${CUPS_CONFDIR}/cupsd.conf
SUPPORT_FILES=		${EGDIR}/classes.conf ${CUPS_CONFDIR}/classes.conf
SUPPORT_FILES+=		${EGDIR}/mime.convs ${CUPS_CONFDIR}/mime.convs
SUPPORT_FILES+=		${EGDIR}/mime.types ${CUPS_CONFDIR}/mime.types
SUPPORT_FILES+=		${EGDIR}/printers.conf ${CUPS_CONFDIR}/printers.conf
RCD_SCRIPTS=		cupsd

OWN_DIRS=		${CUPS_CONFDIR}
OWN_DIRS+=		${CUPS_CONFDIR}/interfaces
OWN_DIRS+=		${CUPS_CONFDIR}/ppd
OWN_DIRS+=		${CUPS_LOGDIR}
OWN_DIRS_PERMS=		${CUPS_CONFDIR}/certs ${CUPS_USER} ${CUPS_GROUP} 0711
OWN_DIRS_PERMS+=	${CUPS_REQUESTS} ${CUPS_USER} ${CUPS_GROUP} 0700
OWN_DIRS_PERMS+=	${CUPS_REQUESTS}/tmp ${CUPS_USER} ${CUPS_GROUP} 1700

pre-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/cups.pam > ${WRKDIR}/cups.pam

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in ENCRYPTION.txt LICENSE.txt README.txt; do		\
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
.if defined(USE_PAM)
	${INSTALL_DATA} ${WRKDIR}/cups.pam ${EGDIR}
.endif

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../net/openslp/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
