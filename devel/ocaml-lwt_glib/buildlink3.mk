# $NetBSD: buildlink3.mk,v 1.2 2026/09/02 19:01:40 wiz Exp $

BUILDLINK_TREE+=	ocaml-lwt_glib

.if !defined(OCAML_LWT_GLIB_BUILDLINK3_MK)
OCAML_LWT_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lwt_glib+=	ocaml-lwt_glib>=1.1.1
BUILDLINK_ABI_DEPENDS.ocaml-lwt_glib+=	ocaml-lwt_glib>=1.1.1nb7
BUILDLINK_PKGSRCDIR.ocaml-lwt_glib?=	../../devel/ocaml-lwt_glib

.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# OCAML_LWT_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lwt_glib
