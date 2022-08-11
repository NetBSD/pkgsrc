# $NetBSD: Makefile,v 1.6 2022/08/11 05:08:45 gutteridge Exp $

DISTNAME=	numix-gtk-theme-2.6.7
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=numixproject/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://numixproject.github.io/products.html
COMMENT=	Modern flat theme with a combination of light and dark elements
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	bash
USE_LANGUAGES=	# none

TOOL_DEPENDS+=	glib2-[0-9]*:../../devel/glib2
TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-sass-[0-9]*:../../www/ruby-sass

DEPENDS+=	gtk2-engines-murrine-[0-9]*:../../x11/gtk2-engines-murrine

REPLACE_BASH+=	scripts/utils.sh

MAKE_FLAGS+=	INSTALL_DIR=${DESTDIR}${PREFIX}/share/themes/Numix
MAKE_FLAGS+=	SASS=${PREFIX}/bin/sass${RUBY_VER}

.include "../../lang/ruby/rubyversion.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
