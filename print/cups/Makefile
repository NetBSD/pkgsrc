# $NetBSD: Makefile,v 1.38 2001/11/19 16:23:11 jlam Exp $

DISTNAME=		cups-${DIST_VERS}-source
PKGNAME=		cups-${VERS}
BASE_VERS=		1.1.10
DIST_VERS=		${BASE_VERS}-1
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

USE_BUILDLINK_ONLY=	# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--sysconfdir=${CONFDIR}
CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/html/cups
CONFIGURE_ARGS+=	--with-cups-user=${CUPS_USER}
CONFIGURE_ARGS+=	--with-cups-group=${CUPS_GROUP}
CONFIGURE_ARGS+=	--enable-libtool-unsupported="${LIBTOOL}"
CONFIGURE_ARGS+=	--enable-slp
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ENV+=		DSOFLAGS="${LDFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if defined(USE_PAM)
.include "../../security/PAM/buildlink.mk"
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

BUILD_DEFS+=		CUPS_USER CUPS_GROUP

DOCDIR=			${PREFIX}/share/doc/cups
EGDIR=			${PREFIX}/share/examples/cups

PKG_USER=		${CUPS_USER}
PKG_USER_DESCR=		Common UNIX Printing System user
PKG_GROUP=		${CUPS_GROUP}

CONF_FILES=		${EGDIR}/client.conf ${CONFDIR}/cups/client.conf
CONF_FILES+=		${EGDIR}/cupsd.conf ${CONFDIR}/cups/cupsd.conf
SUPPORT_FILES=		${EGDIR}/classes.conf ${CONFDIR}/cups/classes.conf
SUPPORT_FILES+=		${EGDIR}/mime.convs ${CONFDIR}/cups/mime.convs
SUPPORT_FILES+=		${EGDIR}/mime.types ${CONFDIR}/cups/mime.types
SUPPORT_FILES+=		${EGDIR}/printers.conf ${CONFDIR}/cups/printers.conf
RCD_SCRIPTS=		${PREFIX}/etc/rc.d/cupsd /etc/rc.d/cupsd

OWN_DIRS+=		${CONFDIR}/cups
OWN_DIRS+=		${CONFDIR}/cups/interfaces
OWN_DIRS+=		${CONFDIR}/cups/ppd
OWN_DIRS+=		/var/log/cups
OWN_DIRS+=		/var/spool/cups
OWN_DIRS_PERMS=		${CONFDIR}/cups/certs ${CUPS_USER} ${CUPS_GROUP} 0711
OWN_DIRS_PERMS+=	/var/spool/cups/tmp ${CUPS_USER} ${CUPS_GROUP} 1700

pre-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/cups.pam > ${WRKDIR}/cups.pam
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/cupsd.sh > ${WRKDIR}/cupsd.sh
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cupsd.sh ${PREFIX}/etc/rc.d/cupsd
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in ENCRYPTION.txt LICENSE.txt README.txt; do		\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR}/$${file};	\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/conf; ${INSTALL_DATA} *.conf mime.* ${EGDIR}
.if defined(USE_PAM)
	${INSTALL_DATA} ${WRKDIR}/cups.pam ${EGDIR}
.endif
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../net/openslp/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
