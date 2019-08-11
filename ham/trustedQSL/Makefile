# $NetBSD: Makefile,v 1.40 2019/08/11 13:21:18 wiz Exp $

DISTNAME=		tqsl-2.4.2
PKGREVISION=		4
CATEGORIES=		ham
MASTER_SITES=		https://sourceforge.net/projects/trustedqsl/files/TrustedQSL/v${PKGVERSION_NOREV}/

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		https://sourceforge.net/projects/trustedqsl/
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

# remove the string $(LIB_SUFFIX), tested with NetBSD at least
SUBST_CLASSES+=		lib-suffix
SUBST_MESSAGE.lib-suffix= Removing $$(LIB_SUFFIX) from src/CMakeLists.txt
SUBST_STAGE.lib-suffix= pre-configure
SUBST_FILES.lib-suffix= src/CMakeLists.txt
SUBST_SED.lib-suffix= 	-e s/\$$\(LIB_SUFFIX\)//

do-configure:
	(cd ${WRKSRC} ; \
	cmake \
	-DBDB_PREFIX=${PREFIX} \
	-DBDB_INCLUDE_DIR=${PREFIX}/include \
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
	# Conflicting PLIST with wxGTK28-2.8.12nb8:
	${RM} -f ${DESTDIR}${PREFIX}/share/locale/*/LC_MESSAGES/wxstd.mo

.include "../../textproc/expat/buildlink3.mk"
.include "../../databases/db5/buildlink3.mk"
.include "../../mk/wxGTK.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
