# $NetBSD: repro.mk,v 1.1 2017/11/12 13:34:14 khorben Exp $
#
# Infrastructure support for PKGSRC_MKREPRO.
#
# Keywords: reproducible
#

.if ${_PKGSRC_MKREPRO} == "yes"

# force ar(1) to be deterministic
TOOLS_CREATE+=	ar
TOOLS_PATH.ar?=	${PKGSRCDIR}/mk/repro/ar
TOOLS_ARGS.ar?=	D

.endif
