# $NetBSD: gtk2hs-buildtools.mk,v 1.1 2025/03/07 13:06:20 pho Exp $
#
# Usage: USE_TOOLS+= gtk2hs-buildtools
#

GTK2HS_BUILDTOOLS_REQD?=	0

.if !empty(USE_TOOLS:Mgtk2hs-buildtools)
TOOLS_DEPENDS.gtk2hs-buildtools?=	gtk2hs-buildtools>=${GTK2HS_BUILDTOOLS_REQD}:../../devel/gtk2hs-buildtools
TOOLS_CREATE+=				gtk2hs-buildtools
TOOLS_PATH.gtk2hs-buildtools=		${PREFIX}/bin/gtk2hs-buildtools
.else
TOOLS_FAIL+=				gtk2hs-buildtools
.endif
