# $NetBSD: Makefile,v 1.2 2005/02/06 13:21:45 taca Exp $

PKGNAME=		postgresql80-docs-${BASE_VERS}
COMMENT=		PostgreSQL database system documentation

.include "../../databases/postgresql80/Makefile.common"

NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_CONFIGURE=	yes

#BUILD_DIRS=	${WRKSRC}/doc
DOCDIR=		${PREFIX}/share/doc/postgresql80

# The manpage documentation is installed with the relevant packages.
#pre-build:
#	cd ${WRKSRC}/doc && ${RM} -f man.tar.gz

do-install:
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
	${TAR} -zxm -C ${DOCDIR} -f ${WRKSRC}/doc/postgres.tar.gz

.include "../../mk/bsd.pkg.mk"
