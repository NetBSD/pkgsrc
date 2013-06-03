# $NetBSD: Makefile,v 1.15 2013/06/03 10:04:52 wiz Exp $
#

DISTNAME=		gummi-0.6.5
PKGREVISION=		6
CATEGORIES=		editors
MASTER_SITES=		http://dev.midnightcoding.org/attachments/download/301/

MAINTAINER=		int21h@pirosfeketefa.hu
HOMEPAGE=		http://dev.midnightcoding.org/projects/gummi
COMMENT=		Gummi is a LaTeX editor, written in C/GTK+
LICENSE=		mit

USE_TOOLS+= 		pkg-config intltool msgfmt gmake

# we need some latex, but not all
#DEPENDS+= teTeX-texmf-[0-9]*:../../print/teTeX3-texmf

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	yes

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
