# $NetBSD: Makefile,v 1.11 2001/11/17 15:50:56 lukem Exp $
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
USERDEL=		/usr/sbin/userdel
GROUPDEL=		/usr/sbin/groupdel
.else
DEPENDS+=		user>=20000313:../../sysutils/user
ADDUSER=		${LOCALBASE}/sbin/useradd
ADDGROUP=		${LOCALBASE}/sbin/groupadd
USERDEL=		${LOCALBASE}/sbin/userdel
GROUPDEL=		${LOCALBASE}/sbin/groupdel
.endif
.elif ${OPSYS} == "SunOS"
ADDUSER=		useradd
ADDGROUP=		groupadd
USERDEL=		userdel
GROUPDEL=		groupdel
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
			--with-statepath=/var/db/nut

pre-configure:
	cd ${WRKSRC} && autoreconf --force

pre-install:
	${SED}  -e 's|@NUT_USER@|${NUT_USER}|g' \
		-e 's|@NUT_GROUP@|${NUT_GROUP}|g' \
		-e 's|@USERDEL@|${USERDEL}|g' \
		-e 's|@GROUPDEL@|${GROUPDEL}|g' \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}  -e 's|@NUT_USER@|${NUT_USER}|g' \
		-e 's|@NUT_GROUP@|${NUT_GROUP}|g' \
		-e 's|@USERDIR@|${USERDIR}|g' \
		-e 's|@ADDUSER@|${ADDUSER}|g' \
		-e 's|@ADDGROUP@|${ADDGROUP}|g' \
		-e 's|@CHGRP@|${CHGRP}|g' \
		-e 's|@ID@|${ID}|g' \
		-e 's|@RM@|${RM}|g' \
		-e 's|@TOUCH@|${TOUCH}|g' \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	${SH} ${INSTALL_FILE}

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

.include "../../mk/bsd.pkg.mk"
