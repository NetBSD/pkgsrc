# $NetBSD: Makefile,v 1.2 2001/12/03 08:06:26 jlam Exp $

.include "../../databases/postgresql/Makefile.common"

PKGNAME=		postgresql-docs-${PG_BASE_VERS}
COMMENT=		PostgreSQL database system documentation

DOC_DIR=		doc
DOCDIR=			${PREFIX}/share/doc/postgresql

# The manpage documentation is installed with the relevant packages.
pre-build:
	cd ${WRKSRC}/${DOC_DIR} && ${RM} -f man.tar.gz

do-build:
	cd ${WRKSRC}/${DOC_DIR} &&					\
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${ALL_TARGET}

do-install:
	cd ${WRKSRC}/${DOC_DIR} &&					\
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_TARGET}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/${DOC_DIR};					\
	${INSTALL_DATA}							\
		FAQ* KNOWN_BUGS MISSING_FEATURES README.* TODO		\
		bug.template internals.ps				\
		${DOCDIR}

.include "../../mk/bsd.pkg.mk"
