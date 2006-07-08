# $NetBSD: buildlink3.mk,v 1.19 2006/07/08 23:10:55 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OCAML_BUILDLINK3_MK:=	${OCAML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ocaml
.endif

BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Nocaml}
BUILDLINK_PACKAGES+=		ocaml
BUILDLINK_ORDER:=		${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ocaml

.if !empty(OCAML_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.08.2
BUILDLINK_ABI_DEPENDS.ocaml+=	ocaml>=3.09.1nb2
BUILDLINK_PKGSRCDIR.ocaml?=	../../lang/ocaml
BUILDLINK_DEPMETHOD.ocaml?=	build

.  include "../../mk/bsd.prefs.mk"
.  if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=		yes
.  endif

PRINT_PLIST_AWK+=	/^@dirrm lib\/ocaml$$/ \
				{ print "@comment in ocaml: " $$0; next }

BUILDLINK_TARGETS+=	ocaml-wrappers
OCAML_WRAPPERS=		ocamlc ocamlc.opt ocamlcp ocamlmklib ocamlmktop \
			ocamlopt ocamlopt.opt
OCAMLBIN_WRAPPERS=	ocaml

.PHONY: ocaml-wrappers
ocaml-wrappers:
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	for w in ${OCAML_WRAPPERS}; do					\
		${SED}  -e 's|@SH@|'${SH:Q}'|g'				\
			-e 's|@OCAML_PREFIX@|${BUILDLINK_PREFIX.ocaml}|g' \
			-e 's|@CFLAGS@|'${CFLAGS:Q}'|g'			\
			-e 's|@LDFLAGS@|'${LDFLAGS:Q}'|g'		\
			< ${.CURDIR:Q}/../../lang/ocaml/files/wrapper.sh \
			> ${BUILDLINK_DIR:Q}/bin/"$$w";			\
		${CHMOD} +x ${BUILDLINK_DIR:Q}/bin/"$$w";		\
	done
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	for w in ${OCAMLBIN_WRAPPERS}; do				\
		${LN} -s ${BUILDLINK_PREFIX.ocaml:Q}/bin/"$$w"		\
		         ${BUILDLINK_DIR:Q}/bin/"$$w";			\
	done

.endif	# OCAML_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
