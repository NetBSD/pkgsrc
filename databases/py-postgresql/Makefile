# $NetBSD: Makefile,v 1.14 2001/05/14 14:53:28 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		py-postgresql-3.2
COMMENT=		Python interface to PostgreSQL

MAINTAINER=		darcy@netbsd.org

DEPENDS+=		postgresql-lib>=${PG_BASE_VERS}:../../databases/postgresql-lib
DEPENDS+=		python>=2.0:../../lang/python
DEPENDS+=		py-mxDateTime-[0-9]*:../../time/py-mxDateTime

PYTHON=			${LOCALBASE}/bin/python

.if exists(${PYTHON})
.if !defined(PYTHON_VERSION)
PYTHON_VERSION!=	${PYTHON} -c "import sys; print sys.version[:3]"
MAKEFLAGS+=		PYTHON_VERSION="${PYTHON_VERSION}"
.endif
.endif

PYTHON_LIBDIR=		lib/python${PYTHON_VERSION}
PLIST_SUBST+=		PYTHON_LIBDIR=${PYTHON_LIBDIR}

MAKE_ENV+=		INSTALLED_LIBPQ=1

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ARGS+=	--with-python-compile
CONFIGURE_ENV+=		PYTHON="${PYTHON}"

DIRS_TO_BUILD=		src/interfaces/python
DOCDIR=			${PREFIX}/share/doc/py-postgresql

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

.include "../../mk/bsd.pkg.mk"
