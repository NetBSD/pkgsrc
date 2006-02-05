# $NetBSD: Makefile,v 1.2 2006/02/05 23:09:57 joerg Exp $
#

PKGREVISION=		1

PERDITION_COMMENT=	main program

.include "options.mk"

USE_PKGINSTALL=		YES
OWN_DIRS+=		${PKG_SYSCONFDIR}
.for f in Makefile.popmap perdition.conf popmap popmap.re
CONF_FILES+=		${EGDIR}/perdition/$f ${PKG_SYSCONFDIR}/${f:.popmap=}
.endfor

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	etc/perdition/perdition.conf
SUBST_SED.paths=	-e "s|/usr/lib/|${PREFIX}/lib/|g" \
			-e "s|/etc/perdition/|${PKG_SYSCONFDIR}/|g"
SUBST_MESSAGE.paths=	Fixing paths.

.include "Makefile.common"
