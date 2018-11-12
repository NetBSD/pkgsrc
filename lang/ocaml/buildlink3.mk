# $NetBSD: buildlink3.mk,v 1.48 2018/11/12 16:09:34 jaapb Exp $

BUILDLINK_TREE+=	ocaml

.if !defined(OCAML_BUILDLINK3_MK)
OCAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=4.07.0
BUILDLINK_ABI_DEPENDS.ocaml+=	ocaml>=4.07.1
BUILDLINK_PKGSRCDIR.ocaml?=	../../lang/ocaml
#BUILDLINK_DEPMETHOD.ocaml?=	build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.ocaml}/lib/ocaml

BUILDLINK_TARGETS+=	ocaml-wrappers
OCAML_WRAPPERS=		ocamlc ocamlc.opt ocamlcp ocamlmklib ocamlmktop \
			ocamlopt ocamlopt.opt
OCAMLBIN_WRAPPERS=	ocaml ocamldep ocamllex ocamlyacc

.PHONY: ocaml-wrappers
ocaml-wrappers:
	${RUN}								\
	for w in ${OCAML_WRAPPERS}; do					\
		${SED}	-e 's|@SH@|'${SH:Q}'|g'				\
			-e 's|@OCAML_PREFIX@|${BUILDLINK_PREFIX.ocaml}|g' \
			-e 's|@CFLAGS@|'${CFLAGS:M*:Q}'|g'			\
			-e 's|@LDFLAGS@|'${LDFLAGS:M*:Q}'|g'		\
			-e 's|@WRAPPEE@|'$$w'|g'			\
			< ${.CURDIR}/../../lang/ocaml/files/wrapper.sh	\
			> ${BUILDLINK_DIR}/bin/"$$w";			\
		${CHMOD} +x ${BUILDLINK_DIR}/bin/"$$w";			\
	done
	${RUN}								\
	for w in ${OCAMLBIN_WRAPPERS}; do				\
		${LN} -s ${BUILDLINK_PREFIX.ocaml}/bin/"$$w"		\
		         ${BUILDLINK_DIR}/bin/"$$w";			\
	done

.include "../../mk/termcap.buildlink3.mk"

.endif # OCAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml
