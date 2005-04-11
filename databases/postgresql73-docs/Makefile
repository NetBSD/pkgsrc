# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:14 tv Exp $

PKGNAME=		postgresql73-docs-${BASE_VERS}
SVR4_PKGNAME=		pstgd
PKGREVISION=		# empty
COMMENT=		PostgreSQL database system documentation


.include "../../databases/postgresql73/Makefile.common"

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
