# $NetBSD: Makefile,v 1.11 2016/03/05 11:27:43 jperkin Exp $
#

PKGNAME=	poco-data-odbc-${POCO_VERSION}
PKGREVISION=	1
CATEGORIES=	databases

COMMENT=	POCO C++ ODBC RDBMS Accessor libraries

.include "../../devel/poco/Makefile.common"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--omit=Data/MySQL,Data/SQLite,Zip,XML
CONFIGURE_ARGS+=	--omit=Foundation,Net,NetSSL_OpenSSL
CONFIGURE_ARGS+=	--no-tests
CONFIGURE_ARGS+=	--no-samples
CONFIGURE_ARGS+=	--odbc-lib=${BUILDLINK_PREFIX.unixodbc}/lib
CONFIGURE_ARGS+=	--odbc-include=${BUILDLINK_PREFIX.unixodbc}/include

USE_TOOLS+=	pax

BUILD_DIRS=		Data/ODBC
INSTALLATION_DIRS=	include/Poco/Data/ODBC lib

do-install:
	# using the same logic as Poco's Makefile install target.
	cd ${WRKSRC} && find lib -name 'libPoco*' -type f -exec cp -f {} \
						    ${DESTDIR}${PREFIX}/lib \;
	cd ${WRKSRC} && find lib -name 'libPoco*' -type l -exec cp -Rf {} \
						    ${DESTDIR}${PREFIX}/lib \;
	cd ${WRKSRC}/Data/ODBC && \
	    ${PAX} -rw -v -pp include ${DESTDIR}${PREFIX}

# should make which odbc we use an option.. but.. :D
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../databases/poco-data/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
