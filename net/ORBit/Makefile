# $NetBSD: Makefile,v 1.5 1998/11/12 16:20:33 agc Exp $
#

DISTNAME=	ORBit-0.3.0
CATEGORIES=	corba
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/ORBit/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	glib-1.1.3:../../devel/glib
DEPENDS+=	gindent-1.9.1:../../devel/gindent

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LIBTOOL_FLAGS=	--install-la

.include "../../mk/bsd.pkg.mk"
