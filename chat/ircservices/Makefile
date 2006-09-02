# $NetBSD: Makefile,v 1.25 2006/09/02 08:42:58 adrianp Exp $
#

DISTNAME=	ircservices-5.0.58
CATEGORIES=	chat
MASTER_SITES=	http://www.ircservices.za.net/download/ \
		ftp://ftp.esper.net/ircservices/ \
		ftp://ftp.esper.net/ircservices/old/ \
		ftp://ftp.freenet.de/pub/ftp.ircservices.za.net/pub/ircservices/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.ircservices.esper.net/
COMMENT=	Services for IRC networks

HAS_CONFIGURE=	YES
USE_TOOLS+=	gmake grep gsed perl
RCD_SCRIPTS=	ircservices
PKG_GROUPS=	services
BUILD_DEFS=	VARBASE

CONFIGURE_ARGS+=	-prefix ${PREFIX:Q}

SUBST_CLASSES+=		install
SUBST_STAGE.install=	post-patch
SUBST_FILES.install=	install-script tools/ircservices-chk.in
SUBST_SED.install=	-e "s|/bin/cp|${CP}|g"
SUBST_SED.install+=	-e "s|/bin/chown|${CHOWN}|g"
SUBST_SED.install+=	-e "s|/bin/chgrp|${CHGRP}|g"
SUBST_SED.install+= 	-e "s|/bin/chmod|${CHMOD}|g"
SUBST_SED.install+= 	-e "s|@DATDEST@|${VARBASE}/run|g"
SUBST_MESSAGE.install=	Fixing scripts.

SUBST_CLASSES+=		utils
SUBST_STAGE.utils=	post-patch
SUBST_FILES.utils=	data/Makefile tools/Makefile
SUBST_SED.utils= 	-e "s|chgrp|${CHGRP}|g"
SUBST_SED.utils+=	-e "s|chmod|${CHMOD}|g"
SUBST_SED.utils+=	-e "s|find|${FIND}|g"
SUBST_MESSAGE.utils=	Fixing paths of hard-coded utilities.

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	data/example-ircservices.conf data/example-modules.conf
SUBST_SED.conf=		-e "s|/usr/local|${PREFIX}|g"
SUBST_SED.conf+=	-e "s|ircservices.log|${VARBASE}/log/ircservices.log|g"
SUBST_SED.conf+=	-e "s|ircservices.pid|${VARBASE}/run/ircservices.pid|g"
SUBST_SED.conf+=	-e "s|/usr/lib/sendmail|/usr/sbin/sendmail|g"
SUBST_MESSAGE.conf=	Fixing configuration files.

CONF_FILES_PERMS=	${PREFIX}/share/examples/ircservices/ircservices.conf \
				${PREFIX}/lib/services/ircservices.conf \
				${BINOWN} ${BINGRP} 0640

CONF_FILES_PERMS+=	${PREFIX}/share/examples/ircservices/modules.conf \
				${PREFIX}/lib/services/modules.conf \
				${BINOWN} ${BINGRP} 0640

INSTALLATION_DIRS=	lib/services ${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.prefs.mk"

# Only some platforms build the dynamically-loadable modules.  On
# others, the modules are statically-linked into the ircservices
# executable.
#
.if exists(${WRKDIR}/${DISTNAME}/modules/mail/main.so)
PLIST_SRC=	${.CURDIR}/PLIST.shared
.endif
PLIST_SRC+=	${.CURDIR}/PLIST

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/ircservices
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ircservices
	${INSTALL_MAN_DIR} ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/docs/*.html \
		${PREFIX}/share/doc/html/ircservices
	${INSTALL_MAN} ${WRKSRC}/docs/*.8 ${PREFIX}/man/man8
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/lib/services/helpfiles
	${INSTALL_DATA} ${WRKSRC}/data/example-ircservices.conf \
		${PREFIX}/share/examples/ircservices/ircservices.conf
	${INSTALL_DATA} ${WRKSRC}/data/example-modules.conf \
		${PREFIX}/share/examples/ircservices/modules.conf

.include "../../mk/bsd.pkg.mk"
