# $NetBSD: Makefile,v 1.1 1998/08/20 22:07:24 agc Exp $
#

DISTNAME=	ORBit-0.2.1
CATEGORIES=	corba
MASTER_SITES=	ftp://ftp.gnome.org/pub/ORBit/

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

DEPENDS+=	glib-1.1.2:../../devel/glib

LIBTOOL_FLAGS=	--install-la

.include "../../mk/bsd.pkg.mk"
