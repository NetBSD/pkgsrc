# $NetBSD: Makefile,v 1.3 1998/09/04 22:00:45 agc Exp $
#

DISTNAME=	ORBit-0.2.1
CATEGORIES=	corba
MASTER_SITES=	ftp://ftp.gnome.org/pub/ORBit/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

DEPENDS+=	glib-1.1.2:../../devel/glib
DEPENDS+=	gindent-1.9.1:../../devel/gindent

LIBTOOL_FLAGS=	--install-la

.include "../../mk/bsd.pkg.mk"
