# $NetBSD: Makefile,v 1.4 2003/07/13 13:52:34 wiz Exp $
#

DISTNAME=	blackbook-3
PKGNAME=	${DISTNAME}.0
PKGREVISION=	2
CATEGORIES=	misc x11
MASTER_SITES=  	${MASTER_SITE_SOURCEFORGE:=blackbook/}

MAINTAINER=	sjr@hispabsd.org
HOMEPAGE=	http://blackbook.sourceforge.net/
COMMENT=	Simple address book (Gtk+ based)

USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_BUILDLINK2=		YES

GNU_CONFIGURE=		YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
