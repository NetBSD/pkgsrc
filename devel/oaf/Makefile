# $NetBSD: Makefile,v 1.16.2.1 2002/06/23 18:44:40 jlam Exp $
#

DISTNAME=		oaf-0.6.10
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/oaf/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		new object activation framework for GNOME

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/popt/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
