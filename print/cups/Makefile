# $NetBSD: Makefile,v 1.35 2001/08/02 03:37:39 jlam Exp $

DISTNAME=		cups-${DIST_VERS}-source
PKGNAME=		cups-${VERS}
BASE_VERS=		1.1.9
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
CONFIGURE_ARGS+=	--sysconfdir=/etc
CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/html/cups
CONFIGURE_ARGS+=	--enable-libtool-unsupported="${LIBTOOL}"
CONFIGURE_ARGS+=	--with-cups-user=${CUPS_USER}
CONFIGURE_ARGS+=	--with-cups-group=${CUPS_GROUP}
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ENV+=		DSOFLAGS="${LDFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if defined(USE_PAM)
.include "../../security/PAM/buildlink.mk"
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

FILES_SUBST=		CUPS_USER=${CUPS_USER}
FILES_SUBST+=		CUPS_GROUP=${CUPS_GROUP}
FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		ADDUSER=${ADDUSER:Q}
FILES_SUBST+=		ADDGROUP=${ADDGROUP:Q}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHGRP=${CHGRP:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CHOWN=${CHOWN:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		GREP=${GREP:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TOUCH=${TOUCH:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/cups.pam > ${WRKDIR}/cups.pam
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
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

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
