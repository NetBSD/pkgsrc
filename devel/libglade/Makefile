# $NetBSD: Makefile,v 1.9 1999/10/10 18:24:43 jlam Exp $
#

DISTNAME=	libglade-0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libglade/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/gnome/

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	gnome-libs-1.0.16:../../x11/gnome-libs
DEPENDS+=	libxml-1.*:../../textproc/libxml

USE_LIBTOOL=	YES
USE_X11BASE=	YES

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

pre-configure:
	${RM} ${WRKSRC}/libgladeConf.sh

.include "../../mk/bsd.pkg.mk"
