# $NetBSD: Makefile,v 1.8 2014/02/12 23:17:40 tron Exp $
#

PKGNAME=	poco-data-odbc-${POCO_VERSION}
PKGREVISION=	2
CATEGORIES=	databases

COMMENT=	POCO C++ ODBC RDBMS Accessor libraries

.include "../../devel/poco/Makefile.common"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--omit=Data/MySQL,Data/SQLite,Zip,XML
CONFIGURE_ARGS+=	--omit=Foundation,Net,NetSSL_OpenSSL
CONFIGURE_ARGS+=	--no-tests
CONFIGURE_ARGS+=	--no-samples

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

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	pkgsrc-izing paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	Data/ODBC/Makefile
SUBST_SED.paths=    -e 's,@ODBCLIBDIR@,${BUILDLINK_DIR}/${BUILDLINK_LIBDIRS.unixodbc},g'
SUBST_SED.paths+=   -e 's,@ODBCINCDIR@,${BUILDLINK_DIR}/${BUILDLINK_INCDIRS.unixodbc},g'

# should make which odbc we use an option.. but.. :D
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../databases/poco-data/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
