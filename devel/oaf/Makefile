# $NetBSD: Makefile,v 1.3 2000/08/31 05:39:25 rh Exp $
#

DISTNAME=		oaf-0.5.1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=/unstable/sources/oaf/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		gnome-libs>=1.2.3:../../x11/gnome-libs
DEPENDS+=		libxml>=1.8.7:../../textproc/libxml

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${X11PREFIX}/include -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
