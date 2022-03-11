# $NetBSD: hacks.mk,v 1.4 2022/03/11 09:01:02 nia Exp $

.if !defined(FONTFORGE_HACKS_MK)
FONTFORGE_HACKS_MK:=

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Old GPLv2 version of msgfmt in NetBSD does not support --desktop/--xml.
TOOLS_PLATFORM.msgfmt=	# none
PKG_HACKS+=		avoid-gplv2-msgfmt
.endif
.endif # FONTFORGE_HACKS_MK
