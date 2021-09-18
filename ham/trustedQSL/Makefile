# $NetBSD: Makefile,v 1.56 2021/09/18 15:03:04 gdt Exp $

DISTNAME=		tqsl-2.5.7
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

# There is an unresolved build failure, where -R for /usr/pkg/lib does
# not precede /usr/X11R7/lib, and on a netbsd-5 system with base xorg,
# an old version of pixman is found by the pkgsrc cairo.  The root
# cause (aside from having two pixman versions installed) is ad hoc -L
# usage in Makefile.am, without matching -R.

CHECK_PORTABILITY_SKIP+=	osx_createdmg.sh

do-configure:
	(cd ${WRKSRC} ; \
	cmake \
	-DBDB_PREFIX=${PREFIX} \
	-DBDB_INCLUDE_DIR=${PREFIX}/include/db5 \
	-DCMAKE_BUILD_WITH_INSTALL_RPATH=TRUE \
	-DCMAKE_INSTALL_PREFIX=${PREFIX} \
	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib \
	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=FALSE \
	-DCMAKE_INSTALL_MANDIR:PATH=${PKGMANDIR} \
	.)

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
# Upstream uses wxGTK28 on Windows because it has accessibility patches, but
# 30 is newer.
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
