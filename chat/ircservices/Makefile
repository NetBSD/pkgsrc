# $NetBSD: Makefile,v 1.9 2004/10/02 22:09:46 adrianp Exp $
#

DISTNAME=	ircservices-5.0.40
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.esper.net/ircservices/ \
		ftp://ftp.esper.net/ircservices/old/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.ircservices.za.net/
COMMENT=	Services for IRC networks

HAS_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make

USE_GNU_TOOLS+=	grep sed
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
