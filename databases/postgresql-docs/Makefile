# $NetBSD: Makefile,v 1.4 2002/10/19 03:03:50 jlam Exp $

PKGNAME=		postgresql-docs-${BASE_VERS}
COMMENT=		PostgreSQL database system documentation

USE_BUILDLINK2=		# defined

.include "../../databases/postgresql/Makefile.common"

BUILD_DIRS=		${WRKSRC}/doc
DOCDIR=			${PREFIX}/share/doc/postgresql

# The manpage documentation is installed with the relevant packages.
pre-build:
	cd ${WRKSRC}/doc && ${RM} -f man.tar.gz

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc; for file in					\
		FAQ* KNOWN_BUGS MISSING_FEATURES README.* TODO		\
		bug.template;						\
	do								\
		${INSTALL_DATA}	$${file} ${DOCDIR}/$${file};		\
	done

.include "../../mk/bsd.pkg.mk"
