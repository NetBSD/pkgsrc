# $NetBSD: Makefile,v 1.2 2004/04/19 22:39:55 recht Exp $

PKGNAME=		postgresql-docs-${BASE_VERS}
SVR4_PKGNAME=		pstgd
COMMENT=		PostgreSQL database system documentation

.include "../../databases/postgresql74/Makefile.common"

NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_CONFIGURE=	yes

#BUILD_DIRS=	${WRKSRC}/doc
DOCDIR=		${PREFIX}/share/doc/postgresql
HTMLDIR=	${PREFIX}/share/doc/html/postgresql

# The manpage documentation is installed with the relevant packages.
#pre-build:
#	cd ${WRKSRC}/doc && ${RM} -f man.tar.gz

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/TODO.detail
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; for file in					\
		FAQ* KNOWN_BUGS MISSING_FEATURES README.* TODO		\
		bug.template;						\
	do								\
		${INSTALL_DATA}	$${file} ${DOCDIR}/$${file};		\
	done
	cd ${WRKSRC}/doc/TODO.detail && \
		${PAX} -rwppm . ${DOCDIR}/TODO.detail
	${TAR} -zxm -C ${HTMLDIR} -f ${WRKSRC}/doc/postgres.tar.gz

.include "../../mk/bsd.pkg.mk"
