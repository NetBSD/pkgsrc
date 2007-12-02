# $NetBSD: Makefile,v 1.21 2007/12/02 13:04:08 wiz Exp $
#

DISTNAME=	metakit-2.4.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://www.equi4.com/pub/mk/ \
		http://www.equi4.com/pub/mk/older/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	Embedded database library

PATCHDIR=	${.CURDIR}/../metakit-lib/patches
DISTINFO_FILE=	${.CURDIR}/../metakit-lib/distinfo
GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	builds
CONFIGURE_SCRIPT= ../unix/configure
CONFIGURE_ARGS+= --with-python=${LOCALBASE}/${PYINC},${LOCALBASE}/${PYSITELIB}
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
BUILD_TARGET=	python
INSTALL_TARGET=	install-python
MAKE_ENV+=	PYINC=${LOCALBASE}/${PYINC} PYSITELIB=${LOCALBASE}/${PYSITELIB}
PY_PATCHPLIST=	yes

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

post-build:
	cd ${WRKSRC}/python && ${PYTHONBIN} ${PYCOMPILEALL} .

post-install:
	${INSTALL_DATA} ${WRKSRC}/python/metakit.pyc ${PREFIX}/${PYSITELIB}

.include "../../databases/metakit-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
