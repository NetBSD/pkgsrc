# $NetBSD: Makefile,v 1.12 2001/01/16 21:59:31 cjones Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.2
PKGNAME=		amanda-common-2.4.2
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"

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
MAKE_ENV+=		CPPFLAGS=-D_LARGEFILE64_SOURCE
ADDUSER=		useradd
ADDGROUP=		groupadd
.endif

CONFIGURE_ARGS+=	--without-server --without-restore --without-client

CPPFLAGS=		# empty

BUILD_DEFS+=		AMANDA_USER AMANDA_SMB AMANDA_VAR

pre-install:
	${SED}  -e 's|@AMUSER@|${AMANDA_USER}|g' \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}  -e 's|@AMUSER@|${AMANDA_USER}|g' \
		-e 's|@AMGROUP@|${AMANDA_GROUP}|g' \
		-e 's|@ADDUSER@|${ADDUSER}|g' \
		-e 's|@ADDGROUP@|${ADDGROUP}|g' \
		-e 's|@CHGRP@|${CHGRP}|g' \
		-e 's|@ID@|${ID}|g' \
		-e 's|@TOUCH@|${TOUCH}|g' \
		-e 's|@RM@|${RM}|g' \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

.include "../../mk/bsd.pkg.mk"
