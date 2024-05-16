# $NetBSD: Makefile,v 1.145 2024/05/16 06:15:04 wiz Exp $

DISTNAME=	fldigi-4.1.01
PKGREVISION=	31
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fldigi/}

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://www.w1hkj.com/
COMMENT=	Digital radio modem
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++11
GNU_CONFIGURE=	yes

# NetBSD 5.1 fails to find strip - install: exec of strip failed:
CONFIGURE_ENV+=		STRIP=${STRIP}

TOOL_DEPENDS+=	asciidoc>=9.0.5:../../textproc/asciidoc

SUBST_CLASSES+=		asciidoc
SUBST_STAGE.asciidoc=	post-configure
SUBST_FILES.asciidoc=	doc/Makefile.am doc/Makefile.in doc/Makefile
SUBST_MESSAGE.asciidoc=	Replacing asciidoc PATH
SUBST_SED.asciidoc=	-e s\|/usr/share\|${PREFIX}/share\|g

SUBST_CLASSES+=		brag-os
SUBST_STAGE.brag-os=	pre-configure
SUBST_FILES.brag-os=	src/misc/newinstall.cxx
SUBST_MESSAGE.brag-os=	Show OS name correctly with Brag button
SUBST_SED.brag-os=	-e s/@@OS@@/${OPSYS}/

# Following binary contains configure parameter, which is OK.
CHECK_WRKREF_SKIP+=	bin/flarq
CHECK_WRKREF_SKIP+=	bin/fldigi

CONFIGURE_ENV.NetBSD+=	ac_cv_header_execinfo_h=no

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-error=c++11-narrowing
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"

FLDIGI_VERSION=	${PKGVERSION_NOREV}
FLARQ_VERSION=	4.3.7

post-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} appbundle
	for f in ${WRKSRC}/src/${DISTNAME}/*.app; do \
		/usr/libexec/PlistBuddy \
			-c 'Add :NSMicrophoneUsageDescription string "Allow for using Sound input devices"' \
			$${f}/Contents/Info.plist; \
	done

INSTALLATION_DIRS+=	Applications
USE_TOOLS+=	pax
post-install:
	cd ${WRKSRC}/src/${DISTNAME} && \
		pax -rw -pp -pm *.app ${DESTDIR}${PREFIX}/Applications

PLIST_SUBST+=	FLDIGI_VERSION=${FLDIGI_VERSION}
PLIST_SUBST+=	FLARQ_VERSION=${FLARQ_VERSION}
GENERATE_PLIST+= (cd ${DESTDIR}${PREFIX} && ${LS} \
		Applications/flarq-${FLARQ_VERSION}.app/Contents/Frameworks/lib*.dylib \
		Applications/fldigi-${FLDIGI_VERSION}.app/Contents/Frameworks/lib*.dylib);

CHECK_SHLIBS_SKIP+=	Applications/flarq-${FLARQ_VERSION}.app/Contents/Frameworks/lib*.dylib
CHECK_SHLIBS_SKIP+=	Applications/fldigi-${FLDIGI_VERSION}.app/Contents/Frameworks/lib*.dylib
CHECK_WRKREF_SKIP+=	Applications/flarq-${FLARQ_VERSION}.app/Contents/MacOS/flarq
CHECK_WRKREF_SKIP+=	Applications/fldigi-${FLDIGI_VERSION}.app/Contents/MacOS/fldigi
.endif

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../ham/flxmlrpc/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../textproc/xmlrpc-c/buildlink3.mk"
#include "../../textproc/json-c/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
