# $NetBSD: buildlink3.mk,v 1.23 2009/05/16 07:22:03 rillig Exp $

BUILDLINK_TREE+=	ocaml

.if !defined(OCAML_BUILDLINK3_MK)
OCAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.08.2
BUILDLINK_ABI_DEPENDS.ocaml+=	ocaml>=3.09.1nb2
BUILDLINK_PKGSRCDIR.ocaml?=	../../lang/ocaml
BUILDLINK_DEPMETHOD.ocaml?=	build

.  include "../../mk/bsd.fast.prefs.mk"
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
	${RUN}								\
	for w in ${OCAML_WRAPPERS}; do					\
		${SED}	-e 's|@SH@|'${SH:Q}'|g'				\
			-e 's|@OCAML_PREFIX@|${BUILDLINK_PREFIX.ocaml}|g' \
			-e 's|@CFLAGS@|'${CFLAGS:Q}'|g'			\
			-e 's|@LDFLAGS@|'${LDFLAGS:Q}'|g'		\
			< ${.CURDIR}/../../lang/ocaml/files/wrapper.sh	\
			> ${BUILDLINK_DIR}/bin/"$$w";			\
		${CHMOD} +x ${BUILDLINK_DIR}/bin/"$$w";			\
	done
	${RUN}								\
	for w in ${OCAMLBIN_WRAPPERS}; do				\
		${LN} -s ${BUILDLINK_PREFIX.ocaml}/bin/"$$w"		\
		         ${BUILDLINK_DIR}/bin/"$$w";			\
	done
.endif # OCAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml
