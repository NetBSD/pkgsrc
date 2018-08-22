# $NetBSD: Makefile,v 1.6 2018/08/22 09:45:13 wiz Exp $
#

HELPLANGUAGE=		pl

DISTNAME=		gimp-help-${GIMPDOCVER}-html-${HELPLANGUAGE}
PKGNAME=		gimp-docs-${HELPLANGUAGE}-${DISTNAME:S/gimp-help-//:S/-html-${HELPLANGUAGE}//}
PKGREVISION=		1

# There is no po/pl/gimp.po in 2.8.1 tarball.
# Use msgfmt and msginit from devel/gettext-tools.
_TOOLS_USE_PKGSRC.msgfmt=	yes

.include "../../graphics/gimp-docs-en/Makefile.common"

COMMENT=		Documentation package for The Gimp image manipulation software
