# $NetBSD: Makefile,v 1.1.1.1 2001/02/16 21:00:26 lukem Exp $
#

DISTNAME=	fugu-1.0
CATEGORIES=	chat
MASTER_SITES=	http://fugu.gale.org/dist/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://fugu.gale.org
COMMENT=	graphical client for the gale secure instant messaging system

DEPENDS+=	rsaref-2.0p3:../../security/rsaref/
DEPENDS+=	py-Pmw>=0.8.5:../../x11/py-Pmw/

GNU_CONFIGURE= 	YES
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/rsaref"

.include "../../mk/bsd.pkg.mk"
