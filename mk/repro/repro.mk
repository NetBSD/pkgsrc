# $NetBSD: repro.mk,v 1.2 2023/05/15 17:16:58 nikita Exp $
#
# Infrastructure support for PKGSRC_MKREPRO.
#
# Keywords: reproducible
#

.if ${PKGSRC_MKREPRO} == "yes"

# force ar(1) to be deterministic
TOOLS_CREATE+=	ar
TOOLS_PATH.ar?=	${PKGSRCDIR}/mk/repro/ar
TOOLS_ARGS.ar?=	D

# force SOURCE_DATE_EPOCH
# https://reproducible-builds.org/docs/source-date-epoch/
# TODO: is this exported in all necessary envs?
PKGSRC_MAKE_ENV+= SOURCE_DATE_EPOCH=1

.endif
