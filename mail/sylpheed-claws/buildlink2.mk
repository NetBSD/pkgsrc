# $NetBSD: buildlink2.mk,v 1.1 2004/01/02 09:14:59 cube Exp $
#
# This Makefile fragment is included by packages that use sylpheed-claws.
#
# This file was created automatically using createbuildlink 2.5.
#

.if !defined(SYLPHEED_CLAWS_BUILDLINK2_MK)
SYLPHEED_CLAWS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			sylpheed-claws
BUILDLINK_DEPENDS.sylpheed-claws?=		sylpheed-claws>=0.9.7nb1
BUILDLINK_PKGSRCDIR.sylpheed-claws?=		../../mail/sylpheed-claws

EVAL_PREFIX+=	BUILDLINK_PREFIX.sylpheed-claws=sylpheed-claws
BUILDLINK_PREFIX.sylpheed-claws_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.sylpheed-claws+=	include/sylpheed/*.h
BUILDLINK_FILES.sylpheed-claws+=	include/sylpheed/common/*.h
BUILDLINK_FILES.sylpheed-claws+=	include/sylpheed/gtk/*.h

BUILDLINK_TARGETS+=	sylpheed-claws-buildlink

sylpheed-claws-buildlink: _BUILDLINK_USE

.endif	# SYLPHEED_CLAWS_BUILDLINK2_MK
