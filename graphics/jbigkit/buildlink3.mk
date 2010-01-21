# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/01/21 12:35:31 obache Exp $

BUILDLINK_TREE+=	jbigkit

.if !defined(JBIGKIT_BUILDLINK3_MK)
JBIGKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jbigkit+=	jbigkit>=2.0
BUILDLINK_PKGSRCDIR.jbigkit?=	../../graphics/jbigkit
.endif # JBIGKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-jbigkit
