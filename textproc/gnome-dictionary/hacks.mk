# $NetBSD: hacks.mk,v 1.1 2022/03/12 07:40:48 nia Exp $

.if !defined(GNOME_DICTIONARY_HACKS_MK)
GNOME_DICTIONARY_HACKS_MK:=

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Old GPLv2 version of msgfmt in NetBSD does not support --desktop/--xml.
TOOLS_PLATFORM.msgfmt=	# none
PKG_HACKS+=		avoid-gplv2-msgfmt
.endif
.endif # GNOME_DICTIONARY_HACKS_MK
