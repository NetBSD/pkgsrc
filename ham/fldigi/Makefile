# $NetBSD: Makefile,v 1.89 2017/05/14 15:22:46 mef Exp $

DISTNAME=	fldigi-4.0.4
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

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-configure
SUBST_FILES.perl=	scripts/fldigi-shell
SUBST_MESSAGE.perl=	Replacing Perl PATH
SUBST_SED.perl=		-e s\|/usr/bin/perl\|${PERL5:Q}\|g

SUBST_CLASSES+=		asciidoc
SUBST_STAGE.asciidoc=	post-configure
SUBST_FILES.asciidoc=	doc/Makefile.am doc/Makefile.in doc/Makefile
SUBST_MESSAGE.asciidoc=	Replacing asciidoc PATH
SUBST_SED.asciidoc=	-e s\|/usr/share\|${PREFIX}/share\|g

SUBST_CLASSES+=		brag-os
SUBST_STAGE.brag-os=	post-patch
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

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
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
