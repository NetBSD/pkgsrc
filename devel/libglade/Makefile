# $NetBSD: Makefile,v 1.4 1999/08/29 12:48:23 rh Exp $
#

DISTNAME=	libglade-0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libglade/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/gnome/

DEPENDS+=	mawk-1.2.2:../../lang/mawk
DEPENDS+=	gnome-libs-1.0.14:../../x11/gnome-libs
DEPENDS+=	libxml-1.4.0:../../textproc/libxml

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
