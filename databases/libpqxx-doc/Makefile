# $NetBSD: Makefile,v 1.1.1.1 2004/01/07 13:38:28 is Exp $
#

PKGNAME=	libpqxx-doc-${LIBPQXX_VERSION}

.include "../../databases/libpqxx/Makefile.common"

COMMENT=	Documentation for libpqxx

NO_CONFIGURE=	yes
NO_BUILD=	yes

PQXXDOCSRC=	${WRKSRC}/doc/html
PQXXDOC=	${PREFIX}/share/doc/html/libpqxx

do-install:
	${INSTALL_DATA_DIR} ${PQXXDOC}
	${INSTALL_DATA_DIR} ${PQXXDOC}/Reference
	${INSTALL_DATA} ${PQXXDOCSRC}/Reference/*.html ${PQXXDOC}/Reference
	${INSTALL_DATA} ${PQXXDOCSRC}/Reference/doxygen.* ${PQXXDOC}/Reference
	${INSTALL_DATA_DIR} ${PQXXDOC}/Tutorial
	${INSTALL_DATA} ${PQXXDOCSRC}/Tutorial/*.html	${PQXXDOC}/Tutorial
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/libpqxx
	${INSTALL_DATA} ${WRKSRC}/test/*.cxx ${PREFIX}/share/examples/libpqxx

.include "../../mk/bsd.pkg.mk"
