# $NetBSD: Makefile,v 1.10 2001/06/11 06:34:29 jlam Exp $
#

DISTNAME=		oaf-0.6.5
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/oaf/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		new object activation framework for GNOME

DEPENDS+=		gnome-libs>=1.2.3:../../x11/gnome-libs
DEPENDS+=		libxml>=1.8.10:../../textproc/libxml

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CPPFLAGS+=		-I${X11PREFIX}/include -I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
