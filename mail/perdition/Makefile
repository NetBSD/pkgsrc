# $NetBSD: Makefile,v 1.20 2023/10/24 22:09:48 wiz Exp $

PERDITION_COMMENT=	main program
PKGREVISION=		7

.include "options.mk"

OWN_DIRS+=		${PKG_SYSCONFDIR}
.for f in Makefile.popmap perdition.conf popmap popmap.re
CONF_FILES+=		${EGDIR}/perdition/${f} ${PKG_SYSCONFDIR}/${f:.popmap=}
.endfor
RCD_SCRIPTS+=		perdition.imap4 perdition.imap4s perdition.pop3 perdition.pop3s

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	etc/perdition/perdition.conf
SUBST_SED.paths=	-e "s|/usr/lib/|${PREFIX}/lib/|g"
SUBST_SED.paths+=	-e "s|/etc/perdition/|${PKG_SYSCONFDIR}/|g"

.include "Makefile.common"
