# $NetBSD: Makefile,v 1.10 2013/09/02 19:51:01 adam Exp $
#

.include "../../editors/gedit3/Makefile.common"

PKGNAME=	${DISTNAME:S/gedit/gedit3-spell/}
PKGREVISION=	5

COMMENT=	Spell-check plugin for gedit

BUILD_DIRS=	plugins/spell
INSTALL_DIRS=	plugins/spell

.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
