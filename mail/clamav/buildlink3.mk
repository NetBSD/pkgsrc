# $NetBSD: buildlink3.mk,v 1.20.2.1 2009/04/10 08:29:37 tron Exp $

BUILDLINK_TREE+=	clamav

.if !defined(CLAMAV_BUILDLINK3_MK)
CLAMAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clamav+=	clamav>=0.95.1
BUILDLINK_PKGSRCDIR.clamav?=	../../mail/clamav

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif	# CLAMAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-clamav
