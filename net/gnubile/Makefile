# $NetBSD: Makefile,v 1.6 2003/05/02 14:16:28 wiz Exp $

DISTNAME=	gnubile-0.20
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://gnutella.wego.com/file_depot/0-10000000/110000-120000/116705/folder/127699/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://gnutella.wego.com/
COMMENT=	Unix Gnutella client for GNOME

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	`xml-config --cflags`

.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
