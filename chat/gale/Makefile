# $NetBSD: Makefile,v 1.6 2001/11/19 04:58:59 lukem Exp $
#

DISTNAME=	gale-0.99a
CATEGORIES=	chat
MASTER_SITES=	http://download.gale.org/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://gale.org
COMMENT=	secure instant messaging system

DEPENDS+=	adns-1.0:../../net/adns/
DEPENDS+=	boehm-gc-5.3:../../devel/boehm-gc/
DEPENDS+=	rsaref-2.0p3:../../security/rsaref/

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
.if exists(/usr/sbin/user)
ADDUSER=	/usr/sbin/useradd
ADDGROUP=	/usr/sbin/groupadd
.else
DEPENDS+=	user>=20000313:../../sysutils/user
ADDUSER=	${LOCALBASE}/sbin/useradd
ADDGROUP=	${LOCALBASE}/sbin/groupadd
.endif
.elif ${OPSYS} == "SunOS"
ADDUSER=	useradd
ADDGROUP=	groupadd
.endif
WRKSRC=		${WRKDIR}/${DISTNAME}
DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

GNU_CONFIGURE= 	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
CPPFLAGS+=	-I${LOCALBASE}/include/rsaref -I${LOCALBASE}/include/w3c-libwww

GALE_USER=	gale
GALE_GROUP=	gale

FILES_SUBST=		GALE_USER=${GALE_USER}
FILES_SUBST+=		GALE_GROUP=${GALE_GROUP}

FILES_SUBST+=		ADDGROUP=${ADDGROUP:Q}
FILES_SUBST+=		ADDUSER=${ADDUSER:Q}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHGRP=${CHGRP:Q}
FILES_SUBST+=		ID=${ID:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		TOUCH=${TOUCH:Q}

FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

.include "../../mk/bsd.pkg.mk"
