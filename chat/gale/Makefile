# $NetBSD: Makefile,v 1.1.1.1 2001/02/06 18:19:11 lukem Exp $
#

DISTNAME=	gale-0.99a
CATEGORIES=	chat
MASTER_SITES=	http://download.gale.org/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://gale.org

DEPENDS+=	adns-1.0:../../net/adns/
DEPENDS+=	boehm-gc-5.3:../../devel/boehm-gc/
DEPENDS+=	rsaref-2.0p3:../../security/rsaref/

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
.if exists(/usr/sbin/user)
ADDUSER=	/usr/sbin/useradd
ADDGROUP=	/usr/sbin/groupadd
USERDEL=	/usr/sbin/userdel
GROUPDEL=	/usr/sbin/groupdel
.else
DEPENDS+=	user>=20000313:../../sysutils/user
ADDUSER=	${LOCALBASE}/sbin/useradd
ADDGROUP=	${LOCALBASE}/sbin/groupadd
USERDEL=	${LOCALBASE}/sbin/userdel
GROUPDEL=	${LOCALBASE}/sbin/groupdel
.endif
.elif ${OPSYS} == "SunOS"
ADDUSER=	useradd
ADDGROUP=	groupadd
USERDEL=	userdel
GROUPDEL=	groupdel
.endif
WRKSRC=		${WRKDIR}/${DISTNAME}
DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

GNU_CONFIGURE= 	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include/rsaref

GALE_USER=	gale
GALE_GROUP=	gale

pre-install:
	${SED}  -e 's|@GALE_USER@|${GALE_USER}|g' \
		-e 's|@GALE_GROUP@|${GALE_GROUP}|g' \
		-e 's|@USERDEL@|${USERDEL}|g' \
		-e 's|@GROUPDEL@|${GROUPDEL}|g' \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}  -e 's|@GALE_USER@|${GALE_USER}|g' \
		-e 's|@GALE_GROUP@|${GALE_GROUP}|g' \
		-e 's|@USERDIR@|${USERDIR}|g' \
		-e 's|@ADDUSER@|${ADDUSER}|g' \
		-e 's|@ADDGROUP@|${ADDGROUP}|g' \
		-e 's|@CHGRP@|${CHGRP}|g' \
		-e 's|@GREP@|${GREP}|g' \
		-e 's|@RM@|${RM}|g' \
		-e 's|@TOUCH@|${TOUCH}|g' \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	${SH} ${INSTALL_FILE}

.include "../../mk/bsd.pkg.mk"
