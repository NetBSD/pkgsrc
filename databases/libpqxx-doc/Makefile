# $NetBSD: Makefile,v 1.4 2012/10/02 21:25:21 asau Exp $
#

PKGNAME=	libpqxx-doc-${LIBPQXX_VERSION}
PKGREVISION=	1

.include "../../databases/libpqxx/Makefile.common"

COMMENT=	Documentation for libpqxx

NO_CONFIGURE=	yes
NO_BUILD=	yes

PQXXDOCSRC=	${WRKSRC}/doc/html
PQXXDOC=	${PREFIX}/share/doc/libpqxx
INSTALLATION_DIRS+=	${PQXXDOC}/Reference ${PQXXDOC}/Tutorial
INSTALLATION_DIRS+=	share/examples/libpqxx

do-install:
	${INSTALL_DATA} ${PQXXDOCSRC}/Reference/*.html \
		${DESTDIR}${PQXXDOC}/Reference
	${INSTALL_DATA} ${PQXXDOCSRC}/Reference/doxygen.* \
		${DESTDIR}${PQXXDOC}/Reference
	${INSTALL_DATA} ${PQXXDOCSRC}/Tutorial/*.html	\
		${DESTDIR}${PQXXDOC}/Tutorial
	${INSTALL_DATA} ${WRKSRC}/test/*.cxx \
		${DESTDIR}${PREFIX}/share/examples/libpqxx

.include "../../mk/bsd.pkg.mk"
