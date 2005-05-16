# $NetBSD: Makefile,v 1.6 2005/05/16 01:32:22 jlam Exp $

PKGNAME=		postgresql74-docs-${BASE_VERS}
SVR4_PKGNAME=		pstgd
COMMENT=		PostgreSQL database system documentation

.include "../../databases/postgresql74/Makefile.common"

NO_BUILD=		yes
NO_CONFIGURE=		yes
PKGSRC_USE_TOOLS+=	tar

#BUILD_DIRS=	${WRKSRC}/doc
DOCDIR=		${PREFIX}/share/doc/postgresql

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
