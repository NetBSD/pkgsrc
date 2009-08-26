# $NetBSD: Makefile,v 1.7 2009/08/26 19:57:26 sno Exp $
#

DISTNAME=		tea-16.0.5
PKGREVISION=		3
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

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
