# $NetBSD: Makefile,v 1.3 2006/02/13 15:18:32 tv Exp $
#

PKGREVISION=		2

PERDITION_COMMENT=	main program

.include "options.mk"

USE_PKGINSTALL=		YES
OWN_DIRS+=		${PKG_SYSCONFDIR}
.for f in Makefile.popmap perdition.conf popmap popmap.re
CONF_FILES+=		${EGDIR}/perdition/$f ${PKG_SYSCONFDIR}/${f:.popmap=}
.endfor
RCD_SCRIPTS+=		perdition.imap4 perdition.imap4s perdition.pop3 perdition.pop3s

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	etc/perdition/perdition.conf
SUBST_SED.paths=	-e "s|/usr/lib/|${PREFIX}/lib/|g" \
			-e "s|/etc/perdition/|${PKG_SYSCONFDIR}/|g"
SUBST_MESSAGE.paths=	Fixing paths.

.include "Makefile.common"
