# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:34 joerg Exp $

PKGNAME=		postgresql73-docs-${BASE_VERS}
PKGREVISION=		1
SVR4_PKGNAME=		pstgd
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
