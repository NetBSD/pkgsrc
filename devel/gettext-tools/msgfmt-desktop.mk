# $NetBSD: msgfmt-desktop.mk,v 1.3 2022/03/18 17:49:46 wiz Exp $

USE_TOOLS+=	msgfmt

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Old GPLv2 version of msgfmt in NetBSD does not support --desktop/--xml.
# XXX technically, we would require gettext-tools >= 0.19.7, as that's
# when the --xml argument was added, rather than >= 0.15, which the tools
# chain currently sets, but this seems non-trivial to adjust.
TOOLS_PLATFORM.msgfmt=	# none
.endif
