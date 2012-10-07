# $NetBSD: options.mk,v 1.1 2012/10/07 14:22:52 mef Exp $

# gcr = ghostscript-cidfonts-ryumin
PKG_OPTIONS_VAR=	PKG_OPTIONS.gcr_type
PKG_SUPPORTED_OPTIONS=	ipa adobe-cidfonts umefont motoya
# Other than adobe-cidfonts options may have problem on dvipdfmx -> gs invocation
# In case for includegraphicx eps file
PKG_SUGGESTED_OPTIONS=	adobe-cidfonts

.include "../../mk/bsd.options.mk"

# -------- Adobe CID font requested -------------
.if !empty(PKG_OPTIONS:Madobe-cidfonts)
GS_CIDFMAP=	cidfmap-adobe
DEPENDS+=	adobe-cidfonts-[0-9]*:../../fonts/adobe-cidfonts
DEPENDS+=	ghostscript-cidfonts-[0-9]*:../../fonts/ghostscript-cidfonts
GCR_INSTALL_TYPE= adobe
.endif

# -------- motoya-fonts (TTF) requested -------------
.if !empty(PKG_OPTIONS:Mmotoya)
GS_CIDFMAP=	cidfmap-motoya
DEPENDS+=	ipafont-[0-9]*:../../fonts/motoya-fonts
GCR_INSTALL_TYPE= ttf
.endif

# -------- umefont (TTF) requested -------------
.if !empty(PKG_OPTIONS:Mumefont)
GS_CIDFMAP=	cidfmap-umefont
DEPENDS+=	ipafont-[0-9]*:../../fonts/umefont-ttf
GCR_INSTALL_TYPE= ttf
.endif

# -------- IPA (TTF) font requested -------------
.if !empty(PKG_OPTIONS:Mipa)
GS_CIDFMAP=	cidfmap-ipa
DEPENDS+=	ipafont-[0-9]*:../../fonts/ipafont
GCR_INSTALL_TYPE= ttf
.endif

# fonts/ja-sazanami-ttf/DESCR:Free Japanese TrueType font based on Wada lab. font (CLWFK) and
# fonts/kochi-ttf/DESCR:Kochi-gothic is a free Japanese TrueType font developed by Yasuyuki Furukawa.
# fonts/monafonts-ttf/DESCR:Japanese Windows font. This is named after ascii art 'mona' used in
# fonts/motoya-fonts/DESCR:Motoya fonts for Android handset display.
# fonts/umefont-ttf/DESCR:This package contains 18 Japanese fonts of Umefont family.
# fonts/vlgothic-ttf/DESCR:Japanese TrueType font using by Vine Linux.
