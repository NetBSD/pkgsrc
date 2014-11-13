# $NetBSD: buildlink3.mk,v 1.1 2014/11/13 11:05:43 markd Exp $

BUILDLINK_TREE+=	baloo

.if !defined(BALOO_BUILDLINK3_MK)
BALOO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.baloo+=	baloo>=4.14.3
BUILDLINK_PKGSRCDIR.baloo?=	../../sysutils/baloo

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/qjson/buildlink3.mk"
#.include "../../mail/akonadi/buildlink3.mk"
#.include "../../misc/kdepimlibs4/buildlink3.mk"
#.include "../../sysutils/kfilemetadata/buildlink3.mk"
#.include "../../textproc/xapian/buildlink3.mk"
#.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# BALOO_BUILDLINK3_MK

BUILDLINK_TREE+=	-baloo
