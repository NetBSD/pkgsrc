# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:07 joerg Exp $

BUILDLINK_TREE+=	boinclibs

.if !defined(BOINC_LIBS_BUILDLINK3_MK)
BOINC_LIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boinclibs+=	boinc3-libs>=3.19.20040714
BUILDLINK_PKGSRCDIR.boinclibs?=	../../net/boinc3-libs

# installs static libraries only
BUILDLINK_DEPMETHOD.boinclibs?=	build
.endif # BOINC_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-boinclibs
