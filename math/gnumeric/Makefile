# $NetBSD: Makefile,v 1.19 2000/06/01 12:07:58 rh Exp $
#

DISTNAME=	gnumeric-0.54
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnumeric/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/gnumeric/

BUILD_DEPENDS+=	${LOCALBASE}/bin/python:../../lang/python
DEPENDS+=	gnome-core-*:../../x11/gnome-core
DEPENDS+=	gnome-print>=0.20:../../print/gnome-print
DEPENDS+=	libxml>=1.8.5:../../textproc/libxml
DEPENDS+=	libglade>=0.13:../../devel/libglade

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_PERL5=	YES
LDFLAGS+=       -L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--without-bonobo
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
