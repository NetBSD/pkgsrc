# $NetBSD: Makefile,v 1.7 2001/05/22 06:05:41 rh Exp $
#

DISTNAME=	libole2-0.2.3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/libole2/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	OLE2 streams parsing library for GNOME

DEPENDS+=	glib>=1.2.8:../../devel/glib

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
