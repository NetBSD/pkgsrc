# $NetBSD: Makefile,v 1.9 2000/12/09 05:53:39 jlam Exp $
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
CONFIGURE_ARGS+=	--disable-pam

CFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/sbin/user)
USERDIR=		/usr/sbin
.else
DEPENDS+=		user>=20000313:../../sysutils/user
USERDIR=		${LOCALBASE}/sbin
.endif

# CUPS_USER	username of the database administrator
# CUPS_GROUP	group of the database administrator
#
CUPS_USER?=		lp
CUPS_GROUP?=		sys

BUILD_DEFS+=		CUPS_USER CUPS_GROUP

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

pre-patch:
	cd ${WRKSRC}/conf; ${MV} cupsd.conf cupsd.conf.in

pre-configure:
	cd ${WRKSRC} && autoconf

post-configure:
	${SED}	-e "s,@CUPS_USER@,${CUPS_USER},g" \
		-e "s,@CUPS_GROUP@,${CUPS_GROUP},g" \
		< ${WRKSRC}/conf/cupsd.conf.in > ${WRKSRC}/conf/cupsd.conf

post-build:
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/cupsd.sh > ${WRKDIR}/cupsd.sh
	${SED}	-e "s,@CUPS_USER@,${CUPS_USER},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@CUPS_USER@,${CUPS_USER},g" \
		-e "s,@CUPS_GROUP@,${CUPS_GROUP},g" \
		-e "s,@USERDIR@,${USERDIR},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cupsd.sh ${PREFIX}/etc/rc.d/cupsd
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cups
	cd ${WRKSRC}/conf; ${INSTALL_DATA} *.conf mime.* \
		${PREFIX}/share/examples/cups
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
