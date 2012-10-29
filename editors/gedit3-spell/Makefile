# $NetBSD: Makefile,v 1.5 2012/10/29 14:48:41 prlw1 Exp $
#

.include "../../editors/gedit3/Makefile.common"

PKGNAME=	${DISTNAME:S/gedit/gedit3-spell/}

COMMENT=	Spell-check plugin for gedit

BUILD_DIRS=	plugins/spell
INSTALL_DIRS=	plugins/spell

.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
