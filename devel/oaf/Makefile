# $NetBSD: Makefile,v 1.8 2001/02/16 14:38:45 wiz Exp $
#

DISTNAME=		oaf-0.6.1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/oaf/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		new object activation framework for GNOME

DEPENDS+=		gnome-libs>=1.2.3:../../x11/gnome-libs
DEPENDS+=		libxml>=1.8.10:../../textproc/libxml
DEPENDS+=		popt-*:../../devel/popt

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${X11PREFIX}/include -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
