# $NetBSD: Makefile,v 1.1.1.1 2004/04/19 00:05:25 recht Exp $

PKGNAME=		postgresql-docs-${BASE_VERS}
SVR4_PKGNAME=		pstgd
COMMENT=		PostgreSQL database system documentation

.include "../../databases/postgresql74/Makefile.common"

BUILD_DIRS=		${WRKSRC}/doc
DOCDIR=			${PREFIX}/share/doc/postgresql

# The manpage documentation is installed with the relevant packages.
pre-build:
	cd ${WRKSRC}/doc && ${RM} -f man.tar.gz

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/TODO.detail
	cd ${WRKSRC}/doc; for file in					\
		FAQ* KNOWN_BUGS MISSING_FEATURES README.* TODO		\
		bug.template;						\
	do								\
		${INSTALL_DATA}	$${file} ${DOCDIR}/$${file};		\
	done
	cd ${WRKSRC}/doc/TODO.detail && \
		${PAX} -rwppm . ${DOCDIR}/TODO.detail

.include "../../mk/bsd.pkg.mk"
