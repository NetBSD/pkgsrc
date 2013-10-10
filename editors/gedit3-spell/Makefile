# $NetBSD: Makefile,v 1.11 2013/10/10 14:42:06 ryoon Exp $
#

.include "../../editors/gedit3/Makefile.common"

PKGNAME=	${DISTNAME:S/gedit/gedit3-spell/}
PKGREVISION=	6

COMMENT=	Spell-check plugin for gedit

BUILD_DIRS=	plugins/spell
INSTALL_DIRS=	plugins/spell

.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
