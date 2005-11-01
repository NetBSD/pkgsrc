# $NetBSD: Makefile,v 1.1.1.1 2005/11/01 03:54:45 dmcmahill Exp $
#

.include "../../cad/wcalc/Makefile.common"

COMMENT=	Meta-pkg for the Wcalc Transmission Line Analysis/Synthesis Calculator

VER=	${DISTNAME:S/wcalc-//}

DEPENDS+=	libwcalc-${VER}*:../../cad/libwcalc
DEPENDS+=	cgi-wcalc-${VER}*:../../cad/cgi-wcalc
DEPENDS+=	sci-wcalc-${VER}*:../../cad/sci-wcalc
DEPENDS+=	stdio-wcalc-${VER}*:../../cad/stdio-wcalc
DEPENDS+=	wcalc-docs-${VER}*:../../cad/wcalc-docs

PKG_OPTIONS_VAR=		PKG_OPTIONS.wcalc
PKG_SUPPORTED_OPTIONS=		mex wcalc-gtk1

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmex-gtk1)
DEPENDS+=	gtk1-wcalc-${VER}*:../../cad/gtk1-wcalc
.else
DEPENDS+=	gtk2-wcalc-${VER}*:../../cad/gtk2-wcalc
.endif

.if !empty(PKG_OPTIONS:Mmex)
# mex-wcalc needs a matlab installation.  In addition, mex-wcalc
# will not currently build correctly if you are using a
# non-native matlab (i.e. linux or solaris matlab on NetBSD)
ONLY_FOR_PLATFORM=	Linux-*-i386 SunOS-*-sparc*
DEPENDS+=	mex-wcalc-${VER}*:../../cad/mex-wcalc
.endif

EXTRACT_ONLY=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined
NO_MTREE=	# defined

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
