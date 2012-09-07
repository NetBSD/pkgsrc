# $NetBSD: Makefile,v 1.47 2012/09/07 19:17:36 adam Exp $

DISTNAME=	gtkspell-2.0.16
PKGREVISION=	9
CATEGORIES=	textproc devel
MASTER_SITES=	http://gtkspell.sourceforge.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtkspell.sourceforge.net/
COMMENT=	Spell checking GtkTextView widget

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	gtkspell-2.0.pc.in

.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
