# $NetBSD: Makefile,v 1.12 2023/10/24 22:08:32 wiz Exp $
#

PKGNAME=	poco-data-${POCO_VERSION}
PKGREVISION=	3
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

BUILD_DIRS=		Data
INSTALLATION_DIRS=	include/Poco/Data lib

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
