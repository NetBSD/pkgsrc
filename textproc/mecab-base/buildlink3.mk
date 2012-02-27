# $NetBSD: buildlink3.mk,v 1.3 2012/02/27 11:53:07 obache Exp $

BUILDLINK_TREE+=	mecab-base

.if !defined(MECAB_BASE_BUILDLINK3_MK)
MECAB_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mecab-base+=	mecab-base>=0.99
BUILDLINK_PKGSRCDIR.mecab-base?=	../../textproc/mecab-base
BUILDLINK_FILES.mecab-base+=		include/mecab.h
BUILDLINK_FILES.mecab-base+=		lib/libmecab.*

.include "../../mk/pthread.buildlink3.mk"
.endif # MECAB_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-mecab-base
