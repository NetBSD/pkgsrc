# $NetBSD: Makefile,v 1.3 2005/12/04 15:49:45 dmcmahill Exp $
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

EXTRACT_ONLY=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-patch:	#empty
do-install:	# empty

.include "../../mk/bsd.pkg.mk"
