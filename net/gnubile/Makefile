# $NetBSD: Makefile,v 1.1.1.1 2001/02/24 23:27:19 tron Exp $

DISTNAME=	gnubile-0.20
CATEGORIES=	net
MASTER_SITES=	http://gnutella.wego.com/file_depot/0-10000000/110000-120000/116705/folder/127699/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://gnutella.wego.com/
COMMENT=	Unix Gnutella client for GNOME

DEPENDS+=	gnome-core-*:../../x11/gnome-core

USE_GMAKE=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="`xml-config --cflags`"

.include "../../mk/bsd.pkg.mk"
