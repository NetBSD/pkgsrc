# $NetBSD: Makefile,v 1.23 2000/10/22 07:37:09 rh Exp $
#

DISTNAME=		gnumeric-0.57
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnumeric/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/gnumeric/

BUILD_DEPENDS+=		${LOCALBASE}/bin/python:../../lang/python
DEPENDS+=		gal>=0.1:../../devel/gal
DEPENDS+=		gb>=0.0.12:../../lang/gb
DEPENDS+=		libole2>=0.1.5:../../devel/libole2
DEPENDS+=		oaf>=0.6.0:../../devel/oaf

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_PERL5=		YES
LDFLAGS+=      		-L${LOCALBASE}/lib
LDFLAGS+=      		-Wl,-R${LOCALBASE}/lib
LDFLAGS+=      		-lunicode
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=		--without-bonobo
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
