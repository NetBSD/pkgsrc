# $NetBSD: Makefile,v 1.6 2004/03/08 19:40:40 jmmv Exp $
#

DISTNAME=	blackbook-3
PKGNAME=	${DISTNAME}.0
PKGREVISION=	3
CATEGORIES=	misc x11
MASTER_SITES=  	${MASTER_SITE_SOURCEFORGE:=blackbook/}

MAINTAINER=	sjr@hispabsd.org
HOMEPAGE=	http://blackbook.sourceforge.net/
COMMENT=	Simple address book (Gtk+ based)

DEPENDS+=		xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_BUILDLINK2=		YES

GNU_CONFIGURE=		YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
