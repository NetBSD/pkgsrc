# $NetBSD: Makefile,v 1.29 2004/01/20 14:11:50 jlam Exp $

PKGNAME=	${PYPKGPREFIX}-postgresql-3.3
PKGREVISION=	2
CATEGORIES=	databases

MAINTAINER=	darcy@NetBSD.org
COMMENT=	Python interface to PostgreSQL

USE_BUILDLINK2=		yes

.include "../postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ARGS+=	--with-python-compile
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"

MAKEFILE=		GNUmakefile
MAKE_ENV+=		INSTALLED_LIBPQ=1
MAKEFLAGS+=		PYTHON_VERSION="${PYVERSSUFFIX}"

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

.include "../postgresql-lib/buildlink2.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
