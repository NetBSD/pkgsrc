# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:49 jlam Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.10.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.gedit?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GEDIT_BUILDLINK3_MK:=	${GEDIT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gedit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngedit}
BUILDLINK_PACKAGES+=	gedit
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gedit

.if !empty(GEDIT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gedit+=	gedit>=2.12.1nb4
BUILDLINK_ABI_DEPENDS.gedit?=	gedit>=2.14.2nb1
BUILDLINK_PKGSRCDIR.gedit?=	../../editors/gedit
.endif	# GEDIT_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../devel/eel2/buildlink3.mk"
#.include "../../devel/gettext-lib/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
#.include "../../devel/popt/buildlink3.mk"
#.include "../../net/ORBit2/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
#.include "../../textproc/aspell/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
