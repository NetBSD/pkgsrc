# $NetBSD: Makefile,v 1.4 2002/03/13 17:37:30 fredb Exp $

DISTNAME=	gnubile-0.20
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://gnutella.wego.com/file_depot/0-10000000/110000-120000/116705/folder/127699/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://gnutella.wego.com/
COMMENT=	Unix Gnutella client for GNOME

DEPENDS+=	gnome-core>=1.4.0.4nb1:../../x11/gnome-core

USE_GMAKE=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	`xml-config --cflags`

.include "../../mk/bsd.pkg.mk"
