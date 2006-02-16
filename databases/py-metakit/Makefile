# $NetBSD: Makefile,v 1.16 2006/02/16 18:13:48 wiz Exp $
#

DISTNAME=	metakit-2.4.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	http://www.equi4.com/pub/mk/ \
		http://www.equi4.com/pub/mk/older/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	Embedded database library

WRKSRC=		${WRKDIR}/metakit-2.4.9.3/builds
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ../unix/configure
CONFIG_GUESS_OVERRIDE=	../unix/scripts/config.guess
CONFIG_SUB_OVERRIDE=	../unix/scripts/config.sub
CONFIG_STATUS_OVERRIDE=	../unix/scripts/config.status
CONFIGURE_ARGS+= --with-python=${LOCALBASE}/${PYINC},${LOCALBASE}/${PYSITELIB}
USE_LIBTOOL=	yes
BUILD_TARGET=	python
INSTALL_TARGET=	install-python
MAKE_ENV+=	PYINC=${LOCALBASE}/${PYINC} PYSITELIB=${LOCALBASE}/${PYSITELIB}
PY_PATCHPLIST=	yes

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

post-build:
	cd ${WRKSRC}/../python && ${PYTHONBIN} ${PYCOMPILEALL} .

post-install:
	${INSTALL_DATA} ${WRKSRC}/../python/metakit.pyc ${PREFIX}/${PYSITELIB}

.include "../../databases/metakit-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
