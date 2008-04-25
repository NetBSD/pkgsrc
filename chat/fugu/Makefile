# $NetBSD: Makefile,v 1.24 2008/04/25 20:39:06 joerg Exp $
#

DISTNAME=	fugu-1.0
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	http://fugu.gale.org/dist/ \
		http://fugu.gale.org/dist/old/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fugu.gale.org/
COMMENT=	Graphical client for the gale secure instant messaging system

PYTHON_VERSIONS_ACCEPTED= 21 # no 22 - uses Makefile.pre.in
PYTHON_PATCH_SCRIPTS=	puffdisp.py pygale/authcache.py pygale/prettypuff.py

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	vi_cv_path_python=${PYTHONBIN:Q}
LDFLAGS+=	-L${BUILDLINK_PREFIX.py-Pmw}/lib \
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.py-Pmw}/lib
CPPFLAGS+=	-I${BUILDLINK_PREFIX.py-Pmw}/include \
		-I${BUILDLINK_PREFIX.rsaref}/include/rsaref \
		-I${BUILDLINK_PREFIX.rsaref}/include

.include "../../lang/python/application.mk"
.include "../../security/rsaref/buildlink3.mk"
.include "../../x11/py-Pmw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
