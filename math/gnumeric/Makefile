# $NetBSD: Makefile,v 1.21 2000/10/15 17:38:54 rh Exp $
#

DISTNAME=	gnumeric-0.56
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnumeric/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/gnumeric/

BUILD_DEPENDS+=	${LOCALBASE}/bin/python:../../lang/python
DEPENDS+=	gnome-core-*:../../x11/gnome-core
DEPENDS+=	gnome-print>=0.23:../../print/gnome-print
DEPENDS+=	libxml>=1.8.7:../../textproc/libxml
DEPENDS+=	libglade>=0.13:../../devel/libglade
DEPENDS+=	libole2>=0.1.5:../../devel/libole2

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_PERL5=	YES
LDFLAGS+=       -L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--without-bonobo
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
