# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/05/19 12:16:25 obache Exp $

BUILDLINK_TREE+=	cabocha

.if !defined(CABOCHA_BUILDLINK3_MK)
CABOCHA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=0.53
BUILDLINK_PKGSRCDIR.cabocha?=	../../textproc/cabocha

.include "../../textproc/yamcha/buildlink3.mk"
.endif	# CABOCHA_BUILDLINK3_MK

BUILDLINK_TREE+=	-cabocha
