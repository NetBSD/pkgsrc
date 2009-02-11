# $NetBSD: Makefile,v 1.22 2009/02/11 21:00:49 joerg Exp $
#

DISTNAME=	metakit-2.4.9.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://www.equi4.com/pub/mk/ \
		http://www.equi4.com/pub/mk/older/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	Embedded database library

PKG_DESTDIR_SUPPORT=	user-destdir

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

INSTALLATION_DIRS+=	${PYSITELIB}

post-build:
	cd ${WRKSRC}/python && ${PYTHONBIN} ${PYCOMPILEALL} .

post-install:
	${INSTALL_DATA} ${WRKSRC}/python/metakit.pyc ${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../databases/metakit-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
