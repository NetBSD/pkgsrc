# $NetBSD: Makefile,v 1.21 2002/10/09 18:24:50 wiz Exp $

PKGNAME=		${PYPKGPREFIX}-postgresql-3.2
COMMENT=		Python interface to PostgreSQL
MAINTAINER=		darcy@netbsd.org

USE_BUILDLINK2=		YES

.include "../../databases/postgresql/Makefile.common"

MAKEFLAGS+=		PYTHON_VERSION="${PYVERSSUFFIX}"

PLIST_SUBST+=		PYTHON_LIBDIR=${PYLIB}
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ARGS+=	--with-python-compile
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
MAKE_ENV+=		INSTALLED_LIBPQ=1

DIRS_TO_BUILD=		src/interfaces/python
DOCDIR=			${PREFIX}/share/doc/${PYPKGPREFIX}-postgresql

do-build:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${ALL_TARGET}
.endfor

do-install:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}
.endfor

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/tutorial
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	for file in ${WRKSRC}/src/interfaces/python/tutorial/*.py; do	\
		${INSTALL_DATA} $${file} ${DOCDIR}/tutorial;		\
	done

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
