# $NetBSD: Makefile,v 1.1.1.1 2000/06/26 21:38:16 rh Exp $
#

DISTNAME=	libole2-0.1.5
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=/unstable/sources/libole2/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	glib>=1.2.8:../../devel/glib

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
