# $NetBSD: buildlink3.mk,v 1.9 2004/12/04 20:31:29 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OCAML_BUILDLINK3_MK:=	${OCAML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ocaml
.endif

BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Nocaml}
BUILDLINK_PACKAGES+=		ocaml
BUILDLINK_DEPMETHOD.ocaml?=	build

.if !empty(OCAML_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ocaml+=	ocaml>=3.06nb6
BUILDLINK_PKGSRCDIR.ocaml?=	../../lang/ocaml

. include "../../mk/bsd.prefs.mk"
. if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=		yes
. endif

PRINT_PLIST_AWK+=	/^@dirrm lib\/ocaml$$/ \
				{ print "@comment in ocaml: " $$0; next }

.endif	# OCAML_BUILDLINK3_MK

.include "../../x11/tk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
