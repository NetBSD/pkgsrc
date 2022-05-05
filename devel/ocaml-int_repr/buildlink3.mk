# $NetBSD: buildlink3.mk,v 1.1 2022/05/05 07:02:21 jaapb Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.18.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.ocaml-int_repr?=	build

BUILDLINK_TREE+=	ocaml-int_repr

.if !defined(OCAML_INT_REPR_BUILDLINK3_MK)
OCAML_INT_REPR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-int_repr+=	ocaml-int_repr>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-int_repr?=	../../devel/ocaml-int_repr

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/ocaml-base/buildlink3.mk"
#.include "../../devel/ocaml-ppx_jane/buildlink3.mk"
.endif	# OCAML_INT_REPR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-int_repr
