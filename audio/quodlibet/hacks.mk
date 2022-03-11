# $NetBSD: hacks.mk,v 1.1 2022/03/11 08:56:02 nia Exp $

.if !defined(QUODLIBET_HACKS_MK)
QUODLIBET_HACKS_MK:=

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Old GPLv2 version of msgfmt in NetBSD does not support --desktop/--xml.
TOOLS_PLATFORM.msgfmt=	# none
PKG_HACKS+=		avoid-gplv2-msgfmt
.endif
.endif # QUODLIBET_HACKS_MK
