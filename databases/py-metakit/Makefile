# $NetBSD: Makefile,v 1.38 2023/08/02 19:20:19 nia Exp $

DISTNAME=	metakit-2.4.9.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://www.equi4.com/pub/mk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	Embedded database library

PATCHDIR=	${.CURDIR}/../metakit-lib/patches
DISTINFO_FILE=	${.CURDIR}/../metakit-lib/distinfo

GNU_CONFIGURE=			yes
CONFIGURE_DIRS=			builds
CONFIGURE_SCRIPT=		../unix/configure
CONFIGURE_ARGS+=		--with-python=${LOCALBASE}/${PYINC},${LOCALBASE}/${PYSITELIB}
USE_LANGUAGES=			c c++
USE_LIBTOOL=			yes
BUILD_TARGET=			python
INSTALL_TARGET=			install-python
MAKE_ENV+=			PYINC=${LOCALBASE}/${PYINC} PYSITELIB=${LOCALBASE}/${PYSITELIB}
PY_PATCHPLIST=			yes
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.4.9.7

# Fails with C++14 default language
FORCE_CXX_STD=		c++03

INSTALLATION_DIRS+=	${PYSITELIB}

post-build:
	cd ${WRKSRC}/python && ${PY_COMPILE_ALL} .

post-install:
	${INSTALL_DATA} ${WRKSRC}/python/metakit.pyc ${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../databases/metakit-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
