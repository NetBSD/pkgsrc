# $NetBSD: Makefile,v 1.16 2004/10/03 00:13:14 tv Exp $
#

DISTNAME=	fugu-1.0
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://fugu.gale.org/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fugu.gale.org/
COMMENT=	Graphical client for the gale secure instant messaging system

PYTHON_VERSIONS_ACCEPTED= 20 21 # no 22 - uses Makefile.pre.in

USE_BUILDLINK3=	YES
GNU_CONFIGURE= 	YES
CONFIGURE_ENV+=	vi_cv_path_python=${PYTHONBIN}
LDFLAGS+=	-L${BUILDLINK_PREFIX.py-Pmw}/lib \
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.py-Pmw}/lib
CPPFLAGS+=	-I${BUILDLINK_PREFIX.py-Pmw}/include \
		-I${BUILDLINK_PREFIX.rsaref}/include/rsaref \
		-I${BUILDLINK_PREFIX.rsaref}/include

.include "../../lang/python/application.mk"
.include "../../security/rsaref/buildlink3.mk"
.include "../../x11/py-Pmw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
