# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:25:32 joerg Exp $

BUILDLINK_TREE+=	opensp

.if !defined(OPENSP_BUILDLINK3_MK)
OPENSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opensp+=	opensp>=1.5.1
BUILDLINK_ABI_DEPENDS.opensp+=	opensp>=1.5.1nb3
BUILDLINK_PKGSRCDIR.opensp?=	../../textproc/opensp

PTHREAD_OPTS+=          require

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # OPENSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensp
