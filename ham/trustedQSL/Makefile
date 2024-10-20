# $NetBSD: Makefile,v 1.80 2024/10/20 14:04:06 wiz Exp $

DISTNAME=		tqsl-2.7.3
PKGREVISION=		1
CATEGORIES=		ham
MASTER_SITES=		http://www.arrl.org/files/file/LoTW%20Instructions/

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		http://www.arrl.org/quick-start-tqsl
COMMENT=		TrustedQSL, uploading QSL Data to LoTW of ARRL
LICENSE=		arrl-license

# A macro _S in /usr/include/ctype.h conflicts with one in apps/tqsltrace.h
# NOT_FOR_PLATFORM+=   NetBSD-5.*

USE_TOOLS+=		perl gmake cmake
# \todo tqsl is not documented to require c++11, but uses c++11 constructs
# \todo tqsl does not add --std=c++11
USE_LANGUAGES+=		c c++11
#SE_CXX_FEATURES+=	c++11
USE_LIBTOOL=		yes

CHECK_PORTABILITY_SKIP+=	osx_createdmg.sh

.include "../../devel/cmake/build.mk"
# \todo Check/rationalize
CMAKE_CONFIGURE_ARGS+=	-DBDB_PREFIX=${PREFIX}
CMAKE_CONFIGURE_ARGS+=	-DBDB_INCLUDE_DIR=${PREFIX}/include/db5
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CONFIGURE_BUILD_WITH_INSTALL_RPATH=TRUE
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CONFIGURE_INSTALL_PREFIX=${PREFIX}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CONFIGURE_INSTALL_RPATH=${PREFIX}/lib
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CONFIGURE_INSTALL_RPATH_USE_LINK_PATH=FALSE
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH=${PKGMANDIR}

# \todo Move to doc
post-install:
	(cd ${WRKSRC} ;\
	${INSTALL_DATA} LICENSE.txt ${DESTDIR}${PREFIX}/share/TrustedQSL/ \
	)

# \todo Perhaps change to lmdb, and (unlikely) consider an option.
.include "../../devel/cmake/build.mk"
.include "../../databases/db5/buildlink3.mk"
#.include "../../databases/lmdb/buildlink3.mk"

.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
