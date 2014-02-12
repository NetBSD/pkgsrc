# $NetBSD: Makefile,v 1.9 2014/02/12 23:17:40 tron Exp $
#

PKGNAME=	poco-data-mysql-${POCO_VERSION}
PKGREVISION=	3
CATEGORIES=	databases

COMMENT=	POCO C++ MySQL RDBMS Accessor libraries

.include "../../devel/poco/Makefile.common"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--omit=Data/SQLite,Data/ODBC,Zip,XML
CONFIGURE_ARGS+=	--omit=Foundation,Net,NetSSL_OpenSSL
CONFIGURE_ARGS+=	--no-tests
CONFIGURE_ARGS+=	--no-samples

USE_TOOLS+=	pax

BUILD_DIRS=		Data/MySQL
INSTALLATION_DIRS=	include/Poco/Data/MySQL lib

do-install:
	# using the same logic as Poco's Makefile install target.
	cd ${WRKSRC} && find lib -name 'libPoco*' -type f -exec cp -f {} \
						    ${DESTDIR}${PREFIX}/lib \;
	cd ${WRKSRC} && find lib -name 'libPoco*' -type l -exec cp -Rf {} \
						    ${DESTDIR}${PREFIX}/lib \;
	cd ${WRKSRC}/Data/MySQL && \
	    ${PAX} -rw -v -pp include ${DESTDIR}${PREFIX}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	pkgsrc-izing paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	Data/MySQL/Makefile
SUBST_SED.paths=    -e 's,@MYSQLLIBDIR@,${BUILDLINK_DIR}/${BUILDLINK_LIBDIRS.mysql-client},g'
SUBST_SED.paths+=    -e 's,@MYSQLINCDIR@,${BUILDLINK_DIR}/${BUILDLINK_INCDIRS.mysql-client},g'

.include "../../mk/mysql.buildlink3.mk"
.include "../../databases/poco-data/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
