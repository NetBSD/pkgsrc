# $NetBSD: Makefile,v 1.4 2011/02/06 14:44:07 wiz Exp $
#

PKGNAME=	poco-data-${POCO_VERSION}
CATEGORIES=	databases

COMMENT=	POCO C++ RDBMS Master Accessor libraries

.include "../../devel/poco/Makefile.common"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--omit=Data/MySQL,Data/ODBC,Zip,XML
CONFIGURE_ARGS+=	--omit=Foundation,Net,NetSSL_OpenSSL
CONFIGURE_ARGS+=	--omit=Data/SQLite
CONFIGURE_ARGS+=	--no-tests
CONFIGURE_ARGS+=	--no-samples

USE_TOOLS+=	pax

INSTALLATION_DIRS=	include/Poco/Data lib
do-build:
	cd ${WRKSRC} && ${TOOLS_GMAKE} POCO_BASE=${WRKSRC} -C Data

do-install:
	# using the same logic as Poco's Makefile install target.
	cd ${WRKSRC} && find lib -name 'libPoco*' -type f -exec cp -f {} \
						    ${DESTDIR}${PREFIX}/lib \;
	cd ${WRKSRC} && find lib -name 'libPoco*' -type l -exec cp -Rf {} \
						    ${DESTDIR}${PREFIX}/lib \;
	cd ${WRKSRC}/Data && \
	    ${PAX} -rw -v -pp include ${DESTDIR}${PREFIX}

.include "../../devel/poco/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
