# $NetBSD: Makefile,v 1.9 2022/03/13 04:27:56 gutteridge Exp $
#

HELPLANGUAGE=		pl

DISTNAME=		gimp-help-${GIMPDOCVER}-html-${HELPLANGUAGE}
PKGNAME=		gimp-docs-${HELPLANGUAGE}-${DISTNAME:S/gimp-help-//:S/-html-${HELPLANGUAGE}//}
PKGREVISION=		3

COMMENT=		Documentation package for The Gimp image manipulation software

# There is no po/pl/gimp.po in 2.8.1 tarball.
# Use msgfmt and msginit from devel/gettext-tools.
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../graphics/gimp-docs-en/Makefile.common"
