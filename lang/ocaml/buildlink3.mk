# $NetBSD: buildlink3.mk,v 1.10 2004/12/24 17:16:04 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OCAML_BUILDLINK3_MK:=	${OCAML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ocaml
.endif

BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Nocaml}
BUILDLINK_PACKAGES+=		ocaml
BUILDLINK_DEPMETHOD.ocaml?=	build

.if !empty(OCAML_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ocaml+=	ocaml>=3.06nb8
BUILDLINK_PKGSRCDIR.ocaml?=	../../lang/ocaml

. include "../../mk/bsd.prefs.mk"
. if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=		yes
. endif

PRINT_PLIST_AWK+=	/^@dirrm lib\/ocaml$$/ \
				{ print "@comment in ocaml: " $$0; next }

.endif	# OCAML_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
