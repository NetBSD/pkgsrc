# $NetBSD: Makefile,v 1.16 1999/10/29 07:53:03 tron Exp $
#

DISTNAME=	libglade-0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libglade/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/gnome/

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	esound-0.2.15:../../audio/esound # do not remove this pre-req
DEPENDS+=	gnome-libs-*:../../x11/gnome-libs
DEPENDS+=	libxml-1.*:../../textproc/libxml

USE_LIBTOOL=	YES
USE_X11BASE=	YES

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

pre-configure:
	${RM} ${WRKSRC}/libgladeConf.sh

.include "../../mk/bsd.pkg.mk"
