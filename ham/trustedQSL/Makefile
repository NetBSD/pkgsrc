# $NetBSD: Makefile,v 1.13 2014/06/13 11:38:03 mef Exp $

DISTNAME=		tqsl-2.0.2
PKGNAME=		tqsl-2.0.2RC4
CATEGORIES=		ham
MASTER_SITES=		http://sourceforge.net/projects/trustedqsl/files/TrustedQSL/v2.0.2/
DIST_SUBDIR=		tqsl-2.0.2RC4

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		http://sourceforge.net/projects/trustedqsl/
COMMENT=		TrustedQSL, uploading QSL Data to LoTW of ARRL
LICENSE=		arrl-license

# A macro _S in /usr/include/ctype.h conflicts with one in apps/tqsltrace.h
# NOT_FOR_PLATFORM+=   NetBSD-5.*

USE_TOOLS+=		perl gmake cmake
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_CMAKE=		yes

# There is an unresolved build failure, where -R for /usr/pkg/lib does
# not precede /usr/X11R7/lib, and on a netbsd-5 system with base xorg,
# an old version of pixman is found by the pkgsrc cairo.  The root
# cause (aside from having two pixman versions installed) is ad hoc -L
# usage in Makefile.am, without matching -R.

do-configure:
	(cd $(WRKSRC) ; \
	cmake \
	-DBDB_PREFIX=${PREFIX} \
	-DBDB_INCLUDE_DIR=${PREFIX}/include \
	-DCMAKE_BUILD_WITH_INSTALL_RPATH=TRUE \
	-DCMAKE_INSTALL_PREFIX=${PREFIX} \
	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib \
	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=FALSE \
	.)

post-install:
	(cd ${WRKSRC} ;\
	${INSTALL_DATA} LICENSE.txt ${DESTDIR}${PREFIX}/share/TrustedQSL/ \
	)
.include "../../textproc/expat/buildlink3.mk"
.include "../../databases/db5/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
