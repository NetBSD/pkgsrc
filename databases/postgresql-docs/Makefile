# $NetBSD: Makefile,v 1.3 2002/04/04 07:41:01 jlam Exp $

PKGNAME=		postgresql-docs-${BASE_VERS}
COMMENT=		PostgreSQL database system documentation

USE_BUILDLINK_ONLY=	YES

.include "../../databases/postgresql/Makefile.common"

DOCDIR=			${PREFIX}/share/doc/postgresql

# The manpage documentation is installed with the relevant packages.
pre-build:
	cd ${WRKSRC}/doc && ${RM} -f man.tar.gz

do-build:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${ALL_TARGET}

do-install:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${INSTALL_TARGET}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc; for file in					\
		FAQ* KNOWN_BUGS MISSING_FEATURES README.* TODO		\
		bug.template;						\
	do								\
		${INSTALL_DATA}	$${file} ${DOCDIR}/$${file};		\
	done

.include "../../mk/bsd.pkg.mk"
