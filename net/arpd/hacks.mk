# $NetBSD: hacks.mk,v 1.2 2006/06/30 15:33:39 tron Exp $

# GCC 4.1.x complains about a NULL argument to memcpy() because it gets
# confused by the definition of the ar_tha() macro under NetBSD.
.include "../../mk/compiler.mk"

.if ${OPSYS} == "NetBSD" && !empty(CC_VERSION:Mgcc-4.1.*)
PKG_HACKS+=		gcc41-null-warning

SUBST_CLASSES+=         gcc41
SUBST_STAGE.gcc41=	post-configure
SUBST_FILES.gcc41=	Makefile
SUBST_SED.gcc41=	-e "s/-Wall/-Wall -Wno-nonnull/"
.endif
