# $NetBSD: buildlink.mk,v 1.1 2002/02/07 15:26:36 jlam Exp $
#
# This Makefile fragment is included by packages that use cdk.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define USE_CDK to force use of cdk.
# (2) Optionally define BUILDLINK_DEPENDS.cdk to the dependency pattern
#     for the version of cdk desired.

.if !defined(CDK_BUILDLINK_MK)
CDK_BUILDLINK_MK=     # defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.cdk?=	cdk>=4.9.6

.if defined(USE_CDK)
_NEED_CDK=		YES
.elif exists(/usr/include/cdk/cdk.h)
_NEED_CDK=		NO
.else
_NEED_CDK=		YES
.endif

.if ${_NEED_CDK} == "YES"
EVAL_PREFIX+=			BUILDLINK_PREFIX.cdk=cdk
BUILDLINK_PREFIX.cdk_DEFAULT=	${LOCALBASE}
DEPENDS+=			${BUILDLINK_DEPENDS.cdk}:../../devel/cdk
.else
BUILDLINK_PREFIX.cdk=		/usr
.endif

BUILDLINK_FILES.cdk=	include/cdk/*.h
BUILDLINK_FILES.cdk+=	lib/libcdk.*

.include "../../devel/ncurses/buildlink.mk"

BUILDLINK_TARGETS.cdk+=	cdk-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.cdk}

pre-configure: ${BUILDLINK_TARGETS.cdk}
cdk-buildlink: _BUILDLINK_USE

.endif  # CDK_BUILDLINK_MK
