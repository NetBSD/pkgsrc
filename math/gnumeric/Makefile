# $NetBSD: Makefile,v 1.30 2001/06/11 06:34:43 jlam Exp $
#

DISTNAME=		gnumeric-0.64
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnumeric/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/gnumeric/
COMMENT=		Powerful and easy to use spreadsheet program from the GNOME project

BUILD_DEPENDS+=		python-2.0:../../lang/python
DEPENDS+=		libglade>=0.16:../../devel/libglade
DEPENDS+=		gal>=0.3:../../devel/gal
DEPENDS+=		gb>=0.0.17:../../lang/gb
DEPENDS+=		libole2>=0.1.7:../../devel/libole2
DEPENDS+=		oaf>=0.6.0:../../devel/oaf

GNU_CONFIGURE=		YES
USE_LIBINTL=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_PERL5=		YES
LDFLAGS+=      		-L${LOCALBASE}/lib
LDFLAGS+=      		-Wl,-R${LOCALBASE}/lib
LDFLAGS+=      		-lunicode
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS=		--without-bonobo
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
