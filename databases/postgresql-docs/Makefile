# $NetBSD: Makefile,v 1.9 2004/04/27 05:44:22 snj Exp $

PKGNAME=		postgresql-docs-${BASE_VERS}
SVR4_PKGNAME=		pstgd
COMMENT=		PostgreSQL database system documentation

USE_BUILDLINK3=		yes

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
