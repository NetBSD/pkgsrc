# $NetBSD: Makefile,v 1.11 2004/04/25 08:47:55 snj Exp $

DISTNAME=	gnubile-0.20
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://gnutella.wego.com/file_depot/0-10000000/110000-120000/116705/folder/127699/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://gnutella.wego.com/
COMMENT=	Unix Gnutella client for GNOME

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
CPPFLAGS+=	`xml-config --cflags`

.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
