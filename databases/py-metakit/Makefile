# $NetBSD: Makefile,v 1.2 2003/03/29 12:40:27 jmmv Exp $
#

DISTNAME=	metakit-2.4.8-38
PKGNAME=	${PYPKGPREFIX}-metakit-2.4.8
WRKSRC=		${WRKDIR}/metakit-2.4.8/builds
CATEGORIES=	databases
MASTER_SITES=	http://www.equi4.com/pub/mk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	embedded database library

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ../unix/configure
CONFIGURE_ARGS+=	--with-tcl= --enable-python
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK2=	yes
ALL_TARGET=	python
INSTALL_TARGET=	install-python
MAKE_ENV+=	PYINC=${LOCALBASE}/${PYINC} PYSITELIB=${LOCALBASE}/${PYSITELIB}
PY_PATCHPLIST=	yes

.include "../../databases/metakit-lib/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
