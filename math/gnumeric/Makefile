# $NetBSD: Makefile,v 1.24 2000/11/25 14:21:24 rh Exp $
#

DISTNAME=		gnumeric-0.59
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnumeric/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/gnumeric/

BUILD_DEPENDS+=		${LOCALBASE}/bin/python:../../lang/python
DEPENDS+=		gal>=0.2.2:../../devel/gal
DEPENDS+=		gb>=0.0.15:../../lang/gb
DEPENDS+=		libole2>=0.1.7:../../devel/libole2
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
