# $NetBSD: Makefile,v 1.1.1.1 2000/07/16 19:44:17 rh Exp $
#

DISTNAME=		oaf-0.4.0
CATEGORIES=		FILLTHISINPLEASE
MASTER_SITES=		${MASTER_SITE_GNOME:=/unstable/sources/oaf/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		ORBit>=0.5.2:../../net/ORBit
DEPENDS+=		glib>=1.2.8:../../devel/glib
DEPENDS+=		libxml>=1.8.7:../../textproc/libxml

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${X11PREFIX}/include"

.include "../../mk/bsd.pkg.mk"
