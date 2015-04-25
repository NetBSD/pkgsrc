# $NetBSD: Makefile,v 1.37 2015/04/25 14:20:43 tnn Exp $
#

DISTNAME=		tea-16.0.5
PKGREVISION=		30
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tea-editor/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tea-editor.sourceforge.net/
#HOMEPAGE=		http://tea.linux.kiev.ua/
COMMENT=		Powerful, easy-to-use text editor for Gtk2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config msgfmt
LDFLAGS.DragonFly=	-lX11 -lm
LDFLAGS.SunOS=		-lX11 -lm

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
