# $NetBSD: Makefile,v 1.27 2001/02/16 14:38:35 wiz Exp $
#

DISTNAME=	libglade-0.14
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/libglade/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/gnome/
COMMENT=	Runtime interpreter for GLADE gui files

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
# do not remove esound pre-requisite
DEPENDS+=	esound>=0.2.18:../../audio/esound
DEPENDS+=	gnome-libs>=1.2.1:../../x11/gnome-libs
DEPENDS+=	libxml>=1.8.5:../../textproc/libxml

USE_LIBINTL=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

pre-configure:
	${RM} ${WRKSRC}/libgladeConf.sh

.include "../../mk/bsd.pkg.mk"
