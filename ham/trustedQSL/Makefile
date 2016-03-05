# $NetBSD: Makefile,v 1.20 2016/03/05 11:28:42 jperkin Exp $

DISTNAME=		tqsl-2.1.3
PKGREVISION=		1
CATEGORIES=		ham
MASTER_SITES=		http://sourceforge.net/projects/trustedqsl/files/TrustedQSL/v${PKGVERSION_NOREV}/

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
	# Conflicting PLIST with wxGTK28-2.8.12nb8:
	${RM} ${DESTDIR}${PREFIX}/share/locale/*/LC_MESSAGES/wxstd.mo

.include "../../textproc/expat/buildlink3.mk"
.include "../../databases/db5/buildlink3.mk"
.include "../../mk/wxGTK.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
