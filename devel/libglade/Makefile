# $NetBSD: Makefile,v 1.18 2000/01/01 13:36:43 rh Exp $
#

DISTNAME=	libglade-0.11
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/libglade/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/gnome/

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	esound-0.2.15:../../audio/esound # do not remove this pre-req
DEPENDS+=	gnome-libs-*:../../x11/gnome-libs
DEPENDS+=	libxml-1.*:../../textproc/libxml

USE_LIBTOOL=	YES
USE_X11BASE=	YES

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

pre-configure:
	${RM} ${WRKSRC}/libgladeConf.sh

.include "../../mk/bsd.pkg.mk"
