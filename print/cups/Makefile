# $NetBSD: Makefile,v 1.14 2000/12/14 17:04:44 jlam Exp $
#

DISTNAME=		cups-1.1.4-source
PKGNAME=		${DISTNAME:S/-source//}
VERS=			${PKGNAME:S/cups-//}
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		print
MASTER_SITES=		ftp://ftp2.easysw.com/pub/cups/${VERS}/ \
			ftp://ftp.easysw.com/pub/cups/${VERS}/ \
			ftp://ftp.northamerica.net/pub/ESP/cups/${VERS}/ \
			ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/cups/${VERS}/ \
			ftp://ftp.fisek.com.tr/pub/cups/${VERS}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.cups.org/

BUILD_DEPENDS+=		autoconf:../../devel/autoconf
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		tiff-*:../../graphics/tiff

USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-libtool-unsupported="${LIBTOOL}"
CONFIGURE_ARGS+=	--enable-rootconfig
CONFIGURE_ARGS+=	--with-cups-user="${CUPS_USER}"
CONFIGURE_ARGS+=	--with-cups-group="${CUPS_GROUP}"

CFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"

.if defined(USE_PAM)
DEPENDS+=		PAM-*:../../security/PAM
CONFIGURE_ARGS+=	--enable-pam
PLIST_SRC=		${PKGDIR}/PLIST.pam
PLIST_SRC+=		${PKGDIR}/PLIST
.else
CONFIGURE_ARGS+=	--disable-pam
PLIST_SRC=		${PKGDIR}/PLIST
.endif

# CUPS_USER	username of the CUPS administrator
# CUPS_GROUP	group of the CUPS administrator
#
CUPS_USER?=		lp
CUPS_GROUP?=		sys

BUILD_DEFS+=		CUPS_USER CUPS_GROUP

.if ${OPSYS} == "NetBSD"
.if exists(/usr/sbin/user)
ADDUSER=		/usr/sbin/useradd
ADDGROUP=		/usr/sbin/groupadd
.else
DEPENDS+=		user>=20000313:../../sysutils/user
ADDUSER=		${LOCALBASE}/sbin/useradd
ADDGROUP=		${LOCALBASE}/sbin/groupadd
.endif
.elif ${OPSYS} == "SunOS"
ADDUSER=		useradd
ADDGROUP=		groupadd
.endif

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

pre-patch:
	cd ${WRKSRC}/conf; ${MV} cupsd.conf cupsd.conf.in

pre-configure:
	cd ${WRKSRC} && autoconf

post-build:
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/cupsd.sh > ${WRKDIR}/cupsd.sh
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/cups.pam > ${WRKDIR}/cups.pam

pre-install:
	${SED}	-e "s,@CUPS_USER@,${CUPS_USER},g" \
		-e "s,@CUPS_GROUP@,${CUPS_GROUP},g" \
		-e "s,@CAT@,${CAT},g" \
		-e "s,@RM@,${RM},g" \
		-e "s,@RMDIR@,${RMDIR},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@CUPS_USER@,${CUPS_USER},g" \
		-e "s,@CUPS_GROUP@,${CUPS_GROUP},g" \
		-e "s,@ADDUSER@,${ADDUSER},g" \
		-e "s,@ADDGROUP@,${ADDGROUP},g" \
		-e "s,@CAT@,${CAT},g" \
		-e "s,@CHGRP@,${CHGRP},g" \
		-e "s,@CHMOD@,${CHMOD},g" \
		-e "s,@CHOWN@,${CHOWN},g" \
		-e "s,@CP@,${CP},g" \
		-e "s,@GREP@,${GREP},g" \
		-e "s,@MKDIR@,${MKDIR},g" \
		-e "s,@RM@,${RM},g" \
		-e "s,@TOUCH@,${TOUCH},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cupsd.sh ${PREFIX}/etc/rc.d/cupsd
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cups
	cd ${WRKSRC}/conf; ${INSTALL_DATA} *.conf mime.* \
		${PREFIX}/share/examples/cups
.if defined(USE_PAM)
	${INSTALL_DATA} ${WRKDIR}/cups.pam ${PREFIX}/share/examples/cups
.endif
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
