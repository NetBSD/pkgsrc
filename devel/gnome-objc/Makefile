# $NetBSD: Makefile,v 1.3 2001/02/16 14:38:28 wiz Exp $
#

DISTNAME=	gnome-objc-1.0.40
CATEGORIES=	devel lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-objc/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Objective C API for gnome and gtk

DEPENDS+=	gnome-libs>=1.2.3:../../x11/gnome-libs
DEPENDS+=	pth>=1.3.7:../../devel/pth

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
