# $NetBSD: Makefile,v 1.4 2012/09/14 12:26:19 drochner Exp $
#

DISTNAME=		gummi-0.6.4
CATEGORIES=		editors
PKGREVISION=		3
MASTER_SITES=		http://dev.midnightcoding.org/attachments/download/298/

MAINTAINER=		int21h@pirosfeketefa.hu
HOMEPAGE=		http://dev.midnightcoding.org/projects/gummi
COMMENT=		Gummi is a LaTeX editor, written in C/GTK+
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+= 		pkg-config intltool msgfmt

# we need some latex, but not all
#DEPENDS+= teTeX-texmf-[0-9]*:../../print/teTeX3-texmf

GNU_CONFIGURE=		YES

AUTO_MKDIRS=		yes

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
