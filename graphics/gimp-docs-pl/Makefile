# $NetBSD: Makefile,v 1.4 2014/03/26 16:18:30 ryoon Exp $
#

HELPLANGUAGE=		pl

DISTNAME=		gimp-help-${GIMPDOCVER}-html-${HELPLANGUAGE}
PKGNAME=		gimp-docs-${HELPLANGUAGE}-${DISTNAME:S/gimp-help-//:S/-html-${HELPLANGUAGE}//}

# There is no po/pl/gimp.po in 2.8.1 tarball.
# Use msgfmt and msginit from devel/gettext-tools.
_TOOLS_USE_PKGSRC.msgfmt=	yes
#TOOL_DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools
#FIND_PREFIX:=		GETTEXTTOOLSDIR=gettext-tools
#.include "../../mk/find-prefix.mk"
#CONFIGURE_ARGS+=	MSGFMT=${GETTEXTTOOLSDIR}/bin/msginit
#CONFIGURE_ARGS+=	MSGINIT=${GETTEXTTOOLSDIR}/bin/msginit

.include "../../graphics/gimp-docs-en/Makefile.common"

COMMENT=		Documentation package for The Gimp image manipulation software
