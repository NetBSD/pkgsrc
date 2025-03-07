# $NetBSD: hpack.mk,v 1.1 2025/03/07 13:06:20 pho Exp $
#
# Usage: USE_TOOLS+= hpack
#
# This generates *.cabal from package.yaml.
#

HPACK_REQD?=	0

.if !empty(USE_TOOLS:Mhpack)
TOOLS_DEPENDS.hpack?=	hs-hpack>=${HPACK_REQD}:../../devel/hs-hpack
TOOLS_CREATE+=		hpack
TOOLS_PATH.hpack=	${PREFIX}/bin/hpack

.PHONY: generate-cabal
pre-configure: generate-cabal
generate-cabal:
	cd ${WRKSRC} && hpack -f
.else
TOOLS_FAIL+=	hpack
.endif
