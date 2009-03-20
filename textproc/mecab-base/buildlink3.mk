# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:31 joerg Exp $

BUILDLINK_TREE+=	mecab-base

.if !defined(MECAB_BASE_BUILDLINK3_MK)
MECAB_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mecab-base+=	mecab-base>=0.90
BUILDLINK_PKGSRCDIR.mecab-base?=	../../textproc/mecab-base
BUILDLINK_FILES.mecab-base+=		include/mecab.h
BUILDLINK_FILES.mecab-base+=		lib/libmecab.*

.include "../../mk/pthread.buildlink3.mk"
.endif # MECAB_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-mecab-base
