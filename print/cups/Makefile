# $NetBSD: Makefile,v 1.27 2001/05/15 17:43:20 jlam Exp $

DISTNAME=		cups-${VERS}-source
PKGNAME=		cups-${VERS}
VERS=			1.1.7
WRKSRC=			${WRKDIR}/cups-${VERS}
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.easysw.com/pub/cups/${VERS}/ \
			ftp://ftp2.easysw.com/pub/cups/${VERS}/ \
			ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/cups/${VERS}/ \
			ftp://ftp.mpg.goe.ni.schule.de/pub/internet/printing/cups/${VERS}/ \
			ftp://ftp.ntua.gr/pub/gnu/cups/${VERS}/ \
			ftp://ftp.fisek.com.tr/pub/cups/${VERS}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.cups.org/
COMMENT=		Common UNIX Printing System

CONFLICTS+=		LPRng-[0-9]* LPRng-core-[0-9]*

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>1.0.9:../../graphics/png
DEPENDS+=		tiff-*:../../graphics/tiff

USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--sysconfdir=/etc
CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/html/cups
CONFIGURE_ARGS+=	--enable-libtool-unsupported="${LIBTOOL}"

USE_SSL=		# defined
CONFIGURE_ARGS+=	--enable-ssl

CFLAGS+=		-I${LOCALBASE}/include
CXXFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS")
DEPENDS+=		zlib>=1.1.3:../../devel/zlib
.endif

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

DOCDIR=			${PREFIX}/share/doc/cups
EGDIR=			${PREFIX}/share/examples/cups

post-extract:
	cd ${WRKSRC}/conf; ${MV} -f cupsd.conf cupsd.conf.in

post-build:
	${SED}	-e "s|@CUPS_USER@|${CUPS_USER}|g"			\
		-e "s|@CUPS_GROUP@|${CUPS_GROUP}|g"			\
		${WRKSRC}/conf/cupsd.conf.in > ${WRKSRC}/conf/cupsd.conf
	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		${FILESDIR}/cups.pam > ${WRKDIR}/cups.pam

pre-install:
	${SED}	-e "s|@CUPS_USER@|${CUPS_USER}|g"			\
		-e "s|@CUPS_GROUP@|${CUPS_GROUP}|g"			\
		-e "s|@CAT@|${CAT}|g"					\
		-e "s|@RM@|${RM}|g"					\
		-e "s|@RMDIR@|${RMDIR}|g"				\
		-e "s|@TRUE@|${TRUE}|g"					\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s|@CUPS_USER@|${CUPS_USER}|g"			\
		-e "s|@CUPS_GROUP@|${CUPS_GROUP}|g"			\
		-e "s|@ADDUSER@|${ADDUSER}|g"				\
		-e "s|@ADDGROUP@|${ADDGROUP}|g"				\
		-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CHGRP@|${CHGRP}|g"				\
		-e "s|@CHMOD@|${CHMOD}|g"				\
		-e "s|@CHOWN@|${CHOWN}|g"				\
		-e "s|@CP@|${CP}|g"					\
		-e "s|@GREP@|${GREP}|g"					\
		-e "s|@MKDIR@|${MKDIR}|g"				\
		-e "s|@RM@|${RM}|g"					\
		-e "s|@TOUCH@|${TOUCH}|g"				\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
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

.include "../../mk/bsd.pkg.mk"
