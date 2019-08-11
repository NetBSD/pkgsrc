# $NetBSD: Makefile,v 1.54 2019/08/11 13:18:03 wiz Exp $
#

DISTNAME=	ircservices-5.0.64
PKGREVISION=	8
CATEGORIES=	chat
#MASTER_SITES=	http://www.ircservices.za.net/download/old/
MASTER_SITES+=	ftp://ftp.esper.net/ircservices/old/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.ircservices.za.net/
COMMENT=	Services for IRC networks
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

HAS_CONFIGURE=	YES
USE_TOOLS+=	gmake grep perl
.if ${OPSYS} != "NetBSD"
USE_TOOLS+=	gsed
.endif
RCD_SCRIPTS=	ircservices
PKG_GROUPS=	services
BUILD_DEFS=	VARBASE

CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-cc ${CC:Q}
CONFIGURE_ARGS+=	${empty(CFLAGS):?:-cflags ${CFLAGS:Q}}
CONFIGURE_ARGS+=	${empty(LDFLAGS):?:-lflags ${LDFLAGS:Q}}
CONFIGURE_ARGS+=	${empty(LIBS):?:-libs ${LIBS:Q}}

SUBST_CLASSES+=		install
SUBST_STAGE.install=	pre-configure
SUBST_FILES.install=	install-script tools/ircservices-chk.in
SUBST_SED.install=	-e "s|/bin/cp|${CP}|g"
SUBST_SED.install+=	-e "s|/bin/chown|${CHOWN}|g"
SUBST_SED.install+=	-e "s|/bin/chgrp|${CHGRP}|g"
SUBST_SED.install+=	-e "s|/bin/chmod|${CHMOD}|g"
SUBST_SED.install+=	-e "s|@DATDEST@|${VARBASE}/run|g"
SUBST_MESSAGE.install=	Fixing scripts.

SUBST_CLASSES+=		utils
SUBST_STAGE.utils=	pre-configure
SUBST_FILES.utils=	data/Makefile tools/Makefile
SUBST_SED.utils=	-e "s|chgrp|${CHGRP}|g"
SUBST_SED.utils+=	-e "s|chmod|${CHMOD}|g"
SUBST_SED.utils+=	-e "s|find|${FIND}|g"
SUBST_MESSAGE.utils=	Fixing paths of hard-coded utilities.

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	data/example-ircservices.conf data/example-modules.conf
SUBST_SED.conf=		-e "s|/usr/local|${PREFIX}|g"
SUBST_SED.conf+=	-e "s|ircservices.log|${VARBASE}/log/ircservices.log|g"
SUBST_SED.conf+=	-e "s|ircservices.pid|${VARBASE}/run/ircservices.pid|g"
SUBST_SED.conf+=	-e "s|/usr/lib/sendmail|/usr/sbin/sendmail|g"
SUBST_MESSAGE.conf=	Fixing configuration files.

CONF_FILES_PERMS=	${PREFIX}/share/examples/ircservices/ircservices.conf \
				${PREFIX}/lib/services/ircservices.conf \
				${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0640

CONF_FILES_PERMS+=	${PREFIX}/share/examples/ircservices/modules.conf \
				${PREFIX}/lib/services/modules.conf \
				${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0640

INSTALLATION_DIRS=	lib/services ${PKGMANDIR}/man8 sbin \
			share/doc/ircservices share/examples/ircservices

INSTALL_MAKE_FLAGS+=	BINDEST=${DESTDIR}${PREFIX}/sbin \
			DATDEST=${DESTDIR}${PREFIX}/lib/services


.include "../../mk/bsd.prefs.mk"

# Only some platforms build the dynamically-loadable modules.  On
# others, the modules are statically-linked into the ircservices
# executable.
#
PLIST_SRC=	${PLIST_SRC_DFLT} ${WRKDIR}/PLIST

pre-install:
	if [ -f ${WRKDIR}/${DISTNAME}/modules/mail/main.so ]; then \
		${CP} ${.CURDIR}/PLIST.shared ${WRKDIR}/PLIST; \
	else \
		${TOUCH} ${WRKDIR}/PLIST; \
	fi

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/*.html \
		${DESTDIR}${PREFIX}/share/doc/ircservices
	${INSTALL_MAN} ${WRKSRC}/docs/*.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${CHOWN} -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/lib/services/helpfiles
	${INSTALL_DATA} ${WRKSRC}/data/example-ircservices.conf \
		${DESTDIR}${PREFIX}/share/examples/ircservices/ircservices.conf
	${INSTALL_DATA} ${WRKSRC}/data/example-modules.conf \
		${DESTDIR}${PREFIX}/share/examples/ircservices/modules.conf

.include "../../mk/bsd.pkg.mk"
