# $NetBSD: Makefile,v 1.11 2014/05/05 00:48:01 ryoon Exp $

DISTNAME=		tqsl-2.0
PKGREVISION=		2
CATEGORIES=		ham
MASTER_SITES=		http://sourceforge.net/projects/trustedqsl/files/TrustedQSL/v2.0/
EXTRACT_SUFX=		.tgz

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		http://sourceforge.net/projects/trustedqsl/
COMMENT=		TrustedQSL, uploading QSL Data to LoTW of ARRL
LICENSE=		arrl-license

# A macro _S in /usr/include/ctype.h conflicts with one in apps/tqsltrace.h
# NOT_FOR_PLATFORM+=   NetBSD-5.*

DEPENDS+=		mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts

USE_TOOLS+=		perl gmake cmake
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_CMAKE=		yes

# There is an unresolved build failure, where -R for /usr/pkg/lib does
# not precede /usr/X11R7/lib, and on a netbsd-5 system with base xorg,
# an old version of pixman is found by the pkgsrc cairo.  The root
# cause (aside from having two pixman versions installed) is ad hoc -L
# usage in Makefile.am, without matching -R.

# Following SUBST is really necessary only on NetBSD-5.*
SUBST_CLASSES+=	macro_S
SUBST_MESSAGE.macro_S= Replace _S with _SS to avoid conflicts on include/ctypes.h and apps/tqsltrace.h
SUBST_STAGE.macro_S= pre-configure
SUBST_FILES.macro_S = \
	apps/crqwiz.cpp \
	apps/extwizard.cpp \
	apps/getpassword.cpp \
	apps/loadcertwiz.cpp \
	apps/qsodatadialog.cpp \
	apps/stationdial.cpp \
	apps/tqsl.cpp \
	apps/tqsl_prefs.cpp \
	apps/tqslhelp.cpp \
	apps/tqsltrace.h \
	apps/tqslvalidator.cpp \
	apps/tqslwiz.cpp
SUBST_SED.macro_S=	-e 's,_S(,_SS(,g'

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
