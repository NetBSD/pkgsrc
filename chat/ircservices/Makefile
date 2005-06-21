# $NetBSD: Makefile,v 1.16 2005/06/21 16:18:52 jlam Exp $
#

DISTNAME=	ircservices-5.0.49
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.esper.net/ircservices/ \
		ftp://ftp.esper.net/ircservices/old/ \
		http://www.ircservices.esper.net/download/ \
		ftp://ftp.freenet.de/pub/ftp.ircservices.za.net/pub/ircservices/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.ircservices.esper.net/
COMMENT=	Services for IRC networks

HAS_CONFIGURE=	YES
USE_PKGINSTALL=	YES
USE_TOOLS+=	gmake grep gsed
USE_PERL5=	build
RCD_SCRIPTS=	ircservices

CONFIGURE_ARGS=	-prefix ${PREFIX}

SUBST_CLASSES=		install utils conf
SUBST_STAGE.install=	post-patch
SUBST_FILES.install=	install-script tools/ircservices-chk.in
SUBST_SED.install=	-e "s|/bin/cp|${CP}|g" \
			-e "s|/bin/chown|${CHOWN}|g" \
			-e "s|/bin/chgrp|${CHGRP}|g" \
			-e "s|/bin/chmod|${CHMOD}|g" \
			-e "s|@DATDEST@|${VARBASE}/run|g"
SUBST_MESSAGE.install=	"Fixing scripts."

SUBST_STAGE.utils=	post-patch
SUBST_FILES.utils=	data/Makefile tools/Makefile
SUBST_SED.utils= 	-e "s|chgrp|${CHGRP}|g" \
			-e "s|chmod|${CHMOD}|g" \
			-e "s|find|${FIND}|g"
SUBST_MESSAGE.utils=	"Fixing paths of hard-coded utilities."

SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	data/example-ircservices.conf data/example-modules.conf
SUBST_SED.conf=		-e "s|/usr/local|${PREFIX}|g" \
			-e "s|ircservices.log|${VARBASE}/log/ircservices.log|g"\
			-e "s|ircservices.pid|${VARBASE}/run/ircservices.pid|g"\
			-e "s|/usr/lib/sendmail|/usr/sbin/sendmail|g"
SUBST_MESSAGE.conf=	"Fixing configuration files."

CONF_FILES_PERMS=	${PREFIX}/share/examples/ircservices/ircservices.conf \
				${PREFIX}/lib/services/ircservices.conf \
				${BINOWN} ${BINGRP} 0640

CONF_FILES_PERMS+=	${PREFIX}/share/examples/ircservices/modules.conf \
				${PREFIX}/lib/services/modules.conf \
				${BINOWN} ${BINGRP} 0640

INSTALLATION_DIRS=	lib/services man/man8 sbin

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
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/lib/services/helpfiles
	${INSTALL_DATA} ${WRKSRC}/data/example-ircservices.conf \
		${PREFIX}/share/examples/ircservices/ircservices.conf
	${INSTALL_DATA} ${WRKSRC}/data/example-modules.conf \
		${PREFIX}/share/examples/ircservices/modules.conf

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
