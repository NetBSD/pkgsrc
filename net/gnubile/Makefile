# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:27 jlam Exp $

DISTNAME=	gnubile-0.20
CATEGORIES=	net
MASTER_SITES=	http://gnutella.wego.com/file_depot/0-10000000/110000-120000/116705/folder/127699/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://gnutella.wego.com/
COMMENT=	Unix Gnutella client for GNOME

DEPENDS+=	gnome-core-[0-9]*:../../x11/gnome-core

USE_GMAKE=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	`xml-config --cflags`

.include "../../mk/bsd.pkg.mk"
