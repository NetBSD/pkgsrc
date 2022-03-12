# $NetBSD: msgfmt-desktop.mk,v 1.1 2022/03/12 08:01:48 nia Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Old GPLv2 version of msgfmt in NetBSD does not support --desktop/--xml.
TOOLS_PLATFORM.msgfmt=	# none
.endif
