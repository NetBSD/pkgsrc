# $NetBSD: Makefile,v 1.7 1999/09/08 16:10:24 rh Exp $
#

DISTNAME=	libglade-0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libglade/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/gnome/

DEPENDS+=	mawk-1.2.2:../../lang/mawk
DEPENDS+=	gnome-libs-1.0.16:../../x11/gnome-libs
DEPENDS+=	libxml-1.6.1:../../textproc/libxml
DEPENDS+=	esound-0.2.8:../../audio/esound

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
