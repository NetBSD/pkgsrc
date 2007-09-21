.if !defined(SPIDERMONKEY_HACKS_MK)
SPIDERMONKEY_HACKS_MK=	# defined

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[34]*)
CFLAGS+=	-fno-strict-aliasing
PKG_HACKS+=	no-strict-aliasing
.endif

.endif
