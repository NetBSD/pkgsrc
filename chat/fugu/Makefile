# $NetBSD: Makefile,v 1.4 2002/09/21 23:46:46 jlam Exp $
#

DISTNAME=	fugu-1.0
CATEGORIES=	chat
MASTER_SITES=	http://fugu.gale.org/dist/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://fugu.gale.org
COMMENT=	graphical client for the gale secure instant messaging system

DEPENDS+=	rsaref-2.0p3:../../security/rsaref/
PYTHON_VERSIONS_ACCEPTED= 20 21 # no 22 - uses Makefile.pre.in

GNU_CONFIGURE= 	YES
CONFIGURE_ENV+=	vi_cv_path_python=${PYTHONBIN}
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/rsaref

.include "../../lang/python/application.mk"
.include "../../x11/py-Pmw/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
