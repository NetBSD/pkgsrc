# $NetBSD: Makefile,v 1.35 2001/08/23 22:40:40 mjl Exp $
#

DISTNAME=		gnumeric-0.70
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnumeric/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/gnumeric/
COMMENT=		Powerful and easy to use spreadsheet program from the GNOME project

BUILD_DEPENDS+=		python>=2.0:../../lang/python
DEPENDS+=		libglade>=0.16:../../devel/libglade
DEPENDS+=		gal>=0.10:../../devel/gal
DEPENDS+=		gb>=0.0.20:../../lang/gb
DEPENDS+=		libole2>=0.2.3:../../devel/libole2
DEPENDS+=		oaf>=0.6.5:../../devel/oaf
DEPENDS+=		libxml>=1.8.14:../../textproc/libxml

GNU_CONFIGURE=		YES
USE_LIBINTL=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_PERL5=		YES
LDFLAGS+=      		-L${LOCALBASE}/lib
LDFLAGS+=      		-Wl,-R${LOCALBASE}/lib
LDFLAGS+=      		-lunicode
CPPFLAGS+=		-I${LOCALBASE}/include
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
