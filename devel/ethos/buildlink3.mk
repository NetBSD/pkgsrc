# $NetBSD: buildlink3.mk,v 1.26 2018/04/16 14:33:46 wiz Exp $

BUILDLINK_TREE+=	ethos

.if !defined(ETHOS_BUILDLINK3_MK)
ETHOS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ethos+=	ethos>=0.2.2
BUILDLINK_ABI_DEPENDS.ethos+=	ethos>=0.2.2nb24
BUILDLINK_PKGSRCDIR.ethos?=	../../devel/ethos

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# ETHOS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ethos
