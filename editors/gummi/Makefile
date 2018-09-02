# $NetBSD: Makefile,v 1.55 2018/09/02 21:32:42 wiz Exp $

DISTNAME=		gummi-0.6.6
PKGREVISION=		18
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GITHUB:=alexandervdm/}
GITHUB_PROJECT=		gummi
GITHUB_TAG=		0.6.6

MAINTAINER=		int21h@pirosfeketefa.hu
HOMEPAGE=		https://github.com/alexandervdm/gummi
COMMENT=		LaTeX editor, written in C/GTK+
LICENSE=		mit

USE_TOOLS+= 		pkg-config intltool msgfmt gmake automake autoreconf
BUILD_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4

# we need some latex, but not all
#DEPENDS+= texlive-collection-all-[0-9]*:../../meta-pkgs/texlive-collection-all

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	yes

AUTO_MKDIRS=		yes

pre-configure:
	cd ${WRKSRC:Q} && ${TOOLS_PATH.autoreconf} -vi

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
