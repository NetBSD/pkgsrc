# $NetBSD: buildlink2.mk,v 1.1 2002/10/16 16:25:10 dillo Exp $
#
# This Makefile fragment is included by packages that use ocaml.

.if !defined(OCAML_BUILDLINK2_MK)
OCAML_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			ocaml
BUILDLINK_DEPENDS.ocaml?=		ocaml>=3.06
BUILDLINK_PKGSRCDIR.ocaml?=		../../lang/ocaml

EVAL_PREFIX+=	BUILDLINK_PREFIX.ocaml=ocaml
BUILDLINK_PREFIX.ocaml_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ocaml+=	lib/ocaml/*.*
BUILDLINK_FILES.ocaml+=	lib/ocaml/caml/*
BUILDLINK_FILES.ocaml+=	lib/ocaml/camlp4/*
BUILDLINK_FILES.ocaml+=	lib/ocaml/labltk/*
BUILDLINK_FILES.ocaml+=	lib/ocaml/ocamldoc/*
BUILDLINK_FILES.ocaml+=	lib/ocaml/threads/*

BUILDLINK_TARGETS+=	ocaml-buildlink

ocaml-buildlink: _BUILDLINK_USE

.endif	# OCAML_BUILDLINK2_MK
