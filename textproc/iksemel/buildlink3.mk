# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/12 03:15:20 jnemeth Exp $

BUILDLINK_TREE+=	iksemel

.if !defined(IKSEMEL_BUILDLINK3_MK)
IKSEMEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.iksemel+=	iksemel>=1.4
BUILDLINK_PKGSRCDIR.iksemel?=	../../textproc/iksemel

#.include "../../security/gnutls/buildlink3.mk"
.endif	# IKSEMEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-iksemel
