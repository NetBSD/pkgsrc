# $NetBSD: Makefile,v 1.6 2002/12/08 02:17:45 salo Exp $
#

DISTNAME=	fugu-1.0
CATEGORIES=	chat
MASTER_SITES=	http://fugu.gale.org/dist/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://fugu.gale.org
COMMENT=	graphical client for the gale secure instant messaging system

PYTHON_VERSIONS_ACCEPTED= 20 21 # no 22 - uses Makefile.pre.in

USE_BUILDLINK2=	YES
GNU_CONFIGURE= 	YES
CONFIGURE_ENV+=	vi_cv_path_python=${PYTHONBIN}
LDFLAGS+=	-L${BUILDLINK_PREFIX.py-Pmw}/lib \
		-Wl,-R${BUILDLINK_PREFIX.py-Pmw}/lib
CPPFLAGS+=	-I${BUILDLINK_PREFIX.py-Pmw}/include \
		-I${BUILDLINK_PREFIX.rsaref}/include/rsaref \
		-I${BUILDLINK_PREFIX.rsaref}/include

.include "../../lang/python/application.mk"
.include "../../security/rsaref/buildlink2.mk"
.include "../../x11/py-Pmw/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
