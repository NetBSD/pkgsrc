# $NetBSD: Makefile,v 1.23 2002/10/25 11:17:24 drochner Exp $

PKGNAME=		${PYPKGPREFIX}-postgresql-3.3
COMMENT=		Python interface to PostgreSQL
MAINTAINER=		darcy@netbsd.org

USE_BUILDLINK2=		# defined

.include "../../databases/postgresql/Makefile.common"

MAKEFLAGS+=		PYTHON_VERSION="${PYVERSSUFFIX}"

PLIST_SUBST+=		PYTHON_LIBDIR=${PYLIB}
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ARGS+=	--with-python-compile
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
MAKE_ENV+=		INSTALLED_LIBPQ=1
MAKEFILE=		GNUmakefile

BUILD_DIRS=		${WRKSRC}/src/interfaces/python
DOCDIR=			${PREFIX}/share/doc/${PYPKGPREFIX}-postgresql

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/tutorial
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	for file in ${WRKSRC}/src/interfaces/python/tutorial/*.py; do	\
		${INSTALL_DATA} $${file} ${DOCDIR}/tutorial;		\
	done

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
