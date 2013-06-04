# $NetBSD: Makefile,v 1.8 2013/06/04 22:15:58 tron Exp $
#

.include "../../editors/gedit3/Makefile.common"

PKGNAME=	${DISTNAME:S/gedit/gedit3-spell/}
PKGREVISION=	3

COMMENT=	Spell-check plugin for gedit

BUILD_DIRS=	plugins/spell
INSTALL_DIRS=	plugins/spell

.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
