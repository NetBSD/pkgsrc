# $NetBSD: Makefile,v 1.20 2012/09/07 19:16:32 adam Exp $
#

DISTNAME=		tea-16.0.5
PKGREVISION=		15
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tea-editor/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tea-editor.sourceforge.net/
#HOMEPAGE=		http://tea.linux.kiev.ua/
COMMENT=		Powerful, easy-to-use text editor for Gtk2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config msgfmt
LDFLAGS.DragonFly=	-lX11 -lm

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
