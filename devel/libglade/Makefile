# $NetBSD: Makefile,v 1.5 1999/09/03 07:20:34 rh Exp $
#

DISTNAME=	libglade-0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libglade/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/gnome/

DEPENDS+=	mawk-1.2.2:../../lang/mawk
DEPENDS+=	gnome-libs-1.0.16:../../x11/gnome-libs
DEPENDS+=	libxml-1.6.1:../../textproc/libxml

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
