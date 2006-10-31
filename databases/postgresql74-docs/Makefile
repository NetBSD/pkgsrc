# $NetBSD: Makefile,v 1.9.6.1 2006/10/31 10:18:19 ghen Exp $

PKGNAME=		postgresql74-docs-${BASE_VERS}
PKGREVISION=		1
SVR4_PKGNAME=		pstgd
COMMENT=		PostgreSQL database system documentation

.include "../../databases/postgresql74/Makefile.common"

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_TOOLS+=		tar

#BUILD_DIRS=	${WRKSRC}/doc
DOCDIR=		${PREFIX}/share/doc/postgresql

# The manpage documentation is installed with the relevant packages.
#pre-build:
#	cd ${WRKSRC}/doc && rm -f man.tar.gz

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/TODO.detail
	cd ${WRKSRC}/doc; for file in					\
		FAQ* KNOWN_BUGS MISSING_FEATURES README.* TODO		\
		bug.template;						\
	do								\
		${INSTALL_DATA}	$${file} ${DOCDIR}/$${file};		\
	done
	cd ${WRKSRC}/doc/TODO.detail && pax -rwppm . ${DOCDIR}/TODO.detail
	tar -zxm -C ${DOCDIR} -f ${WRKSRC}/doc/postgres.tar.gz

.include "../../mk/bsd.pkg.mk"
