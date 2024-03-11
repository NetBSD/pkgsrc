# $NetBSD: Makefile,v 1.101 2024/03/11 21:15:57 wiz Exp $

DISTNAME=		gummi-0.6.6
PKGREVISION=		61
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GITHUB:=alexandervdm/}
GITHUB_PROJECT=		gummi
GITHUB_TAG=		0.6.6

MAINTAINER=		int21h@pirosfeketefa.hu
HOMEPAGE=		https://github.com/alexandervdm/gummi
COMMENT=		LaTeX editor, written in C/GTK+
LICENSE=		mit

USE_TOOLS+=		pkg-config intltool msgfmt gmake automake autoreconf
TOOL_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4

# we need some latex, but not all
#DEPENDS+=	texlive-collection-all-[0-9]*:../../meta-pkgs/texlive-collection-all

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	yes

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-export-dynamic

AUTO_MKDIRS=		yes

pre-configure:
	cd ${WRKSRC} && ${TOOLS_PATH.autoreconf} -vi

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
