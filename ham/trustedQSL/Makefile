# $NetBSD: Makefile,v 1.77 2024/05/29 16:33:07 adam Exp $

DISTNAME=		tqsl-2.6.5
PKGREVISION=		13
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
USE_LIBTOOL=		yes
USE_CMAKE=		yes

CHECK_PORTABILITY_SKIP+=	osx_createdmg.sh

# \todo Check/rationalize
CMAKE_ARGS+=		-DBDB_PREFIX=${PREFIX}
CMAKE_ARGS+=		-DBDB_INCLUDE_DIR=${PREFIX}/include/db5
CMAKE_ARGS+=		-DCMAKE_BUILD_WITH_INSTALL_RPATH=TRUE
CMAKE_ARGS+=		-DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_ARGS+=		-DCMAKE_INSTALL_RPATH=${PREFIX}/lib
CMAKE_ARGS+=		-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=FALSE
CMAKE_ARGS+=		-DCMAKE_INSTALL_MANDIR:PATH=${PKGMANDIR}

# \todo Move to doc
post-install:
	(cd ${WRKSRC} ;\
	${INSTALL_DATA} LICENSE.txt ${DESTDIR}${PREFIX}/share/TrustedQSL/ \
	)

# \todo Perhaps change to lmdb, and (unlikely) consider an option.
.include "../../databases/db5/buildlink3.mk"
#.include "../../databases/lmdb/buildlink3.mk"

.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
