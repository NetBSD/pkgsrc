# $NetBSD: Makefile,v 1.13 2001/11/21 03:22:05 simonb Exp $
#

DISTNAME=		nut-0.45.2
PKGNAME=		ups-nut-0.45.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.exploits.org/nut/release/

MAINTAINER=		lukem@netbsd.org
HOMEPAGE=		http://www.exploits.org/nut/
COMMENT=		Network UPS Tools

.include "../../mk/bsd.prefs.mk"
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
DEINSTALL_FILE=         ${WRKDIR}/DEINSTALL
INSTALL_FILE=           ${WRKDIR}/INSTALL
BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf

GNU_CONFIGURE=		yes
NUT_DOCDIR=		${LOCALBASE}/share/doc/nut
NUT_USER=		nut
NUT_GROUP=		nut
CONFIGURE_ARGS+=	--sysconfdir=${LOCALBASE}/etc/nut \
			--with-user=${NUT_USER} \
			--with-group=${NUT_GROUP} \
			--with-statepath=/var/db/nut \
			--with-modelpath=${LOCALBASE}/sbin/ups-drivers

FILES_SUBST=		NUT_USER=${NUT_USER}
FILES_SUBST+=		NUT_GROUP=${NUT_GROUP}

FILES_SUBST+=		ADDGROUP=${ADDGROUP:Q}
FILES_SUBST+=		ADDUSER=${ADDUSER:Q}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHGRP=${CHGRP:Q}
FILES_SUBST+=		ID=${ID:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		TOUCH=${TOUCH:Q}

FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-configure:
	cd ${WRKSRC} && autoreconf --force

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	@${SED} -e "/%%PREFIX%%/s##${LOCALBASE}#g" \
		${FILESDIR}/upsd \
		>${LOCALBASE}/etc/rc.d/upsd
	@${CHMOD} 0755 ${LOCALBASE}/etc/rc.d/upsd
	@${INSTALL} -d -o ${NUT_USER} -g ${NUT_GROUP} -m 0770 /var/db/nut
	@if ! [ -d ${NUT_DOCDIR} ]; then ${MKDIR} ${NUT_DOCDIR}; fi
	@if ! [ -d ${NUT_DOCDIR}/cables ]; then ${MKDIR} ${NUT_DOCDIR}/cables; fi
	${INSTALL_DATA} ${WRKSRC}/docs/cables/*.txt ${NUT_DOCDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/Changes.trust ${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${NUT_DOCDIR}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
