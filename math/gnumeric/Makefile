# $NetBSD: Makefile,v 1.26 2001/02/17 18:22:23 wiz Exp $
#

DISTNAME=		gnumeric-0.61
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnumeric/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/gnumeric/
COMMENT=		Powerful and easy to use spreadsheet program from the GNOME project

BUILD_DEPENDS+=		${LOCALBASE}/bin/python:../../lang/python
DEPENDS+=		gal>=0.3:../../devel/gal
DEPENDS+=		gb>=0.0.17:../../lang/gb
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
