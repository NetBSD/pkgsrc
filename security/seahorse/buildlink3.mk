# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:11:08 jlam Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.10.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.seahorse?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SEAHORSE_BUILDLINK3_MK:=	${SEAHORSE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	seahorse
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nseahorse}
BUILDLINK_PACKAGES+=	seahorse
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}seahorse

.if !empty(SEAHORSE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.seahorse+=	seahorse>=0.8.1
BUILDLINK_ABI_DEPENDS.seahorse?=	seahorse>=0.8.1nb2
BUILDLINK_PKGSRCDIR.seahorse?=	../../security/seahorse
.endif	# SEAHORSE_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../databases/gnome-mime-data/buildlink3.mk"
#.include "../../devel/libglade2/buildlink3.mk"
#.include "../../devel/libgnomeui/buildlink3.mk"
#.include "../../net/libsoup-devel/buildlink3.mk"
#.include "../../security/gpgme/buildlink3.mk"
#.include "../../sysutils/gnome-vfs2/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
