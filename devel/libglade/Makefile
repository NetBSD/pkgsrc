# $NetBSD: Makefile,v 1.25 2000/10/17 17:07:44 rh Exp $
#

DISTNAME=	libglade-0.14
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/libglade/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/gnome/

DEPENDS+=	gettext>=0.10.35nb1:../../devel/gettext
# do not remove esound pre-requisite
DEPENDS+=	esound>=0.2.18:../../audio/esound
DEPENDS+=	gnome-libs>=1.2.1:../../x11/gnome-libs
DEPENDS+=	libxml>=1.8.5:../../textproc/libxml

USE_LIBTOOL=	YES
USE_X11BASE=	YES

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

pre-configure:
	${RM} ${WRKSRC}/libgladeConf.sh

.include "../../mk/bsd.pkg.mk"
