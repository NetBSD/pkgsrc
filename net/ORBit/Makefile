# $NetBSD: Makefile,v 1.4 1998/10/05 14:02:06 agc Exp $
#

DISTNAME=	ORBit-0.3.0
CATEGORIES=	corba
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/ORBit/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

DEPENDS+=	glib-1.1.3:../../devel/glib
DEPENDS+=	gindent-1.9.1:../../devel/gindent

LIBTOOL_FLAGS=	--install-la

.include "../../mk/bsd.pkg.mk"
