# $NetBSD: Makefile,v 1.34 2004/07/24 22:45:15 recht Exp $

PKGNAME=	${PYPKGPREFIX}-postgresql-3.3
PKGREVISION=	3
CATEGORIES=	databases python

MAINTAINER=	darcy@NetBSD.org
COMMENT=	Python interface to PostgreSQL

USE_BUILDLINK3=		yes

.include "../postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ARGS+=	--with-python-compile
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"

MAKEFILE=		GNUmakefile
MAKE_ENV+=		INSTALLED_LIBPQ=1
MAKEFLAGS+=		PYTHON_VERSION=${PYVERSSUFFIX}

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}

BUILD_DIRS=		${WRKSRC}/src/interfaces/python
DOCDIR=			${PREFIX}/share/doc/${PYPKGPREFIX}-postgresql

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/tutorial
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	for file in ${WRKSRC}/src/interfaces/python/tutorial/*.py; do	\
		${INSTALL_DATA} $${file} ${DOCDIR}/tutorial;		\
	done

.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
