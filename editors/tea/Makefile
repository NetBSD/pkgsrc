# $NetBSD: Makefile,v 1.1.1.1 2007/04/14 04:49:08 reed Exp $
#

DISTNAME=		tea-16.0.5
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tea-editor/} \
			http://tea.linux.kiev.ua/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tea-editor.sourceforge.net/
#HOMEPAGE=		http://tea.linux.kiev.ua/
COMMENT=		Powerful, easy-to-use text editor for Gtk2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
