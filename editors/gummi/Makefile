# $NetBSD: Makefile,v 1.105 2024/10/15 16:15:32 adam Exp $

DISTNAME=		gummi-0.8.3
PKGREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GITHUB:=alexandervdm/}

MAINTAINER=		int21h@pirosfeketefa.hu
HOMEPAGE=		https://github.com/alexandervdm/gummi
COMMENT=		LaTeX editor, written in C/GTK+
LICENSE=		mit

USE_TOOLS+=		pkg-config intltool msgfmt gmake automake autoreconf
TOOL_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4

# we need some latex, but not all
#DEPENDS+=	texlive-collection-all-[0-9]*:../../meta-pkgs/texlive-collection-all

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-export-dynamic

pre-configure:
	cd ${WRKSRC} && ${TOOLS_PATH.autoreconf} -vi

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../textproc/gtkspell3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
# for synctex
.include "../../print/web2c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
