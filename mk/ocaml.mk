# $NetBSD: ocaml.mk,v 1.28 2020/04/21 11:23:29 jaapb Exp $
#
# This Makefile fragment handles the common variables used by OCaml packages.
#
# Build def variables:
# OCAML_USE_OPT_COMPILER 
# if set to yes, will enable optimised (native code) compilation
# default value: depends on architecture
#
# PLIST variable:
# PLIST.ocaml-opt for files only installed when using the optimised compiler
# Set based on OCAML_USE_OPT_COMPILER
# 
# Package-settable variables:
# OCAML_USE_FINDLIB
# package uses findlib infrastructure
# OCAML_FINDLIB_DIRS
# directories under OCAML_SITELIBDIR that this package installs into
# OCAML_FINDLIB_REGISTER
# register findlib directories into OCaml ld.conf
# OCAML_USE_OASIS [implies OCAML_USE_FINDLIB]
# package uses oasis infrastructure
# OCAML_USE_OASIS_DYNRUN [implies OCAML_USE_OASIS]
# package uses oasis.dynrun
# OCAML_USE_OPAM
# package uses OPAM installer [implies OCAML_USE_FINDLIB]
# OCAML_USE_TOPKG
# package uses topkg [implies OCAML_USE_FINDLIB]
# OCAML_USE_JBUILDER
# package uses jbuilder [implies OCAML_USE_OPAM]
# OCAML_USE_DUNE
# package uses dune [implies OCAML_USE_OPAM]
# OCAML_TOPKG_DOCDIR
# different targets for topkg (bytecode, optional bytecode, native)
# OASIS_BUILD_ARGS
# arguments for oasis build
# Set by this file:
# OCAML_SITELIBDIR

.if !defined(OCAML_MK)
OCAML_MK= # defined

.include "../../mk/bsd.fast.prefs.mk"

BUILD_DEFS+=	OCAML_USE_OPT_COMPILER

_VARGROUPS+=	ocaml
_PKG_VARS.ocaml=	\
	OCAML_USE_FINDLIB \
	OCAML_FINDLIB_DIRS \
	OCAML_FINDLIB_REGISTER \
	OCAML_USE_OASIS \
	OCAML_USE_OASIS_DYNRUN \
	OASIS_BUILD_ARGS \
	OCAML_USE_OPAM \
	OCAML_USE_TOPKG \
	OCAML_TOPKG_NAME \
	OCAML_TOPKG_DOCDIR \
	OCAML_TOPKG_FLAGS \
	OCAML_TOPKG_TARGETS \
	OCAML_TOPKG_OPTIONAL_TARGETS \
	OCAML_USE_JBUILDER \
	JBUILDER_BUILD_FLAGS \
	JBUILDER_BUILD_PACKAGES \
	JBUILDER_BUILD_TARGETS \
	OCAML_USE_DUNE \
	DUNE_BUILD_FLAGS \
	DUNE_BUILD_PACKAGES \
	DUNE_BUILD_TARGETS \
	OCAML_BUILD_ARGS \
	OPAM_INSTALL_DIR \
	OPAM_INSTALL_FILES
_DEF_VARS.ocaml=	\
	OCAML_USE_OPT_COMPILER
_SYS_VARS.ocaml=	\
	OCAML_SITELIBDIR

# Default value of OCAML_USE_FINDLIB
OCAML_USE_FINDLIB?=	no

# Default value of OCAML_USE_OASIS
OCAML_USE_OASIS?=	no

# Default value of OCAML_USE_OASIS_DYNRUN
OCAML_USE_OASIS_DYNRUN?=	no

# Default value of OCAML_USE_TOPKG
OCAML_USE_TOPKG?=	no

# Default value of OCAML_USE_JBUILDER
OCAML_USE_JBUILDER?=	no

# Default value of OCAML_USE_DUNE
OCAML_USE_DUNE?=	no

OCAML_TOPKG_NAME?=	${PKGBASE:S/^ocaml-//}
OCAML_TOPKG_DOCDIR?=	${PREFIX}/share/doc
OCAML_TOPKG_FLAGS?=	# empty
OCAML_TOPKG_TARGETS?=	# empty
OCAML_TOPKG_OPTIONAL_TARGETS?=	# empty
OCAML_TOPKG_NATIVE_TARGETS?=	# empty

OPAM_INSTALL_FILES?=	${OCAML_TOPKG_NAME}
JBUILDER_BUILD_FLAGS?=	# empty
JBUILDER_BUILD_TARGETS?=	@install
JBUILDER_BUILD_PACKAGES?=	# empty
DUNE_BUILD_FLAGS?=	# empty
DUNE_BUILD_TARGETS?=	@install
DUNE_BUILD_PACKAGES?=	# empty

# Default value of OASIS_BUILD_ARGS
OASIS_BUILD_ARGS?=	# empty

# Default value of OCAML_USE_OPT_COMPILER
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    !empty(MACHINE_ARCH:M*arm*) || (${MACHINE_ARCH} == "aarch64") || \
    (${MACHINE_ARCH} == "x86_64")
OCAML_USE_OPT_COMPILER?=	yes
.else
OCAML_USE_OPT_COMPILER?=	no
.endif

#
# Configure stuff for OASIS_DYNRUN
#
.if ${OCAML_USE_OASIS_DYNRUN} == "yes"
.include "../../devel/ocaml-oasis/buildlink3.mk"
OCAML_USE_OASIS=	yes
.endif

#
# Configure stuff for OASIS
#
.if ${OCAML_USE_OASIS} == "yes"
OCAML_USE_FINDLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--destdir "${DESTDIR}"
CONFIGURE_ARGS+=	--prefix "${PREFIX}"
# Force use of native code compiler according to setting
.if ${OCAML_USE_OPT_COMPILER} == "yes"
CONFIGURE_ARGS+=	--override is_native true
.else
CONFIGURE_ARGS+=	--override is_native false
.endif
.endif

# Configure stuff for JBUILDER/DUNE
.if ${OCAML_USE_JBUILDER} == "yes"
.include "../../devel/ocaml-jbuilder/buildlink3.mk"
OCAML_USE_OPAM?=	yes
.elif ${OCAML_USE_DUNE} == "yes"
.include "../../devel/ocaml-dune/buildlink3.mk"
OCAML_USE_OPAM?=	yes
OPAM_INSTALL_DIR?=	_build/default
.else
OCAML_USE_OPAM?=	no
.endif

# Configure stuff for OPAM
.if ${OCAML_USE_OPAM} == "yes"
.include "../../misc/ocaml-opaline/buildlink3.mk"
OCAML_USE_FINDLIB=	yes
.endif

# Configure stuff for TOPKG
.if ${OCAML_USE_TOPKG} == "yes"
.include "../../misc/ocaml-topkg/buildlink3.mk"
OCAML_USE_FINDLIB=	yes
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/${OCAML_TOPKG_NAME}
.endif

# Fallback value for OPAM_INSTALL_DIR
OPAM_INSTALL_DIR?=	.

# Value for OCAML_SITELIBDIR
OCAML_SITELIBDIR=	lib/ocaml/site-lib
MAKE_ENV+=	OCAML_SITELIBDIR="${OCAML_SITELIBDIR}"
PLIST_SUBST+=	OCAML_SITELIB="${OCAML_SITELIBDIR}"

PRINT_PLIST_AWK+=	{ gsub(/${OCAML_SITELIBDIR:S|/|\\/|g}/, \
			"$${OCAML_SITELIB}"); \
			print; next; }

.if ${OCAML_USE_FINDLIB} == "yes"
.include "../../devel/ocaml-findlib/buildlink3.mk"
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}
OCAML_FINDLIB_DIRS?=	${PKGBASE:S/^ocaml-//}
OCAML_FINDLIB_REGISTER?=	yes
.endif

#
# Compiler stuff
#

# Things that get installed with the opt compiler
PLIST_VARS+=	ocaml-opt

.if ${OCAML_USE_OPT_COMPILER} == "yes"
# The opt compiler needs the C compiler suite
USE_LANGUAGES+=	c
PLIST.ocaml-opt=	yes
.else
# If we're bytecode compiling, don't strip executables
INSTALL_UNSTRIPPED=	yes
.endif

#
# OASIS targets
#
.if ${OCAML_USE_OASIS} == "yes"
# OASIS uses ocamlbuild
.include "../../devel/ocamlbuild/buildlink3.mk"
.if ${OCAML_USE_OASIS_DYNRUN} == "yes"
pre-configure:
	${RUN} cd ${WRKSRC} && ocamlfind ocamlc -linkpkg -package oasis.dynrun -o setup setup.ml && ${RM} setup.cmo setup.cmi

OASIS_EXEC=./setup
.else
OASIS_EXEC=ocaml setup.ml
.endif

# Redefine configure target
do-configure:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${OASIS_EXEC} -configure ${CONFIGURE_ARGS}

# Redefine build target
do-build:
	${RUN} ${_ULIMIT_CMD} cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${OASIS_EXEC} -build ${OASIS_BUILD_ARGS}

# Redefine install target
do-install:
	${RUN} cd ${WRKSRC} && \
		${OASIS_EXEC} -install --destdir ${DESTDIR} --prefix ${PREFIX}
.endif

#
# topkg targets
#
.if ${OCAML_USE_TOPKG} == "yes"

do-build:
	${RUN} ${_ULIMIT_CMD} cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ocaml pkg/pkg.ml build ${OCAML_TOPKG_FLAGS}

.endif # topkg

#
# opam targets
#
.if ${OCAML_USE_OPAM} == "yes" 

do-install:
	${RUN} for i in ${OPAM_INSTALL_FILES}; do \
		cd ${WRKSRC} && opaline -install-cmd "${INSTALL_DATA}" \
		-exec-install-cmd "${INSTALL_PROGRAM}" \
		-name $$i \
		-destdir ${DESTDIR} \
		-prefix ${PREFIX} \
		-libdir ${PREFIX}/${OCAML_SITELIBDIR} \
		-docdir ${OCAML_TOPKG_DOCDIR}/$$i \
		-stublibsdir ${PREFIX}/${OCAML_SITELIBDIR}/stublibs \
		-bindir ${PREFIX}/bin \
		${OPAM_INSTALL_DIR}/$$i.install; \
	done

.endif # opam

#
# jbuilder targets
#
.if ${OCAML_USE_JBUILDER} == "yes"

do-build:
.if !empty(JBUILDER_BUILD_PACKAGES)
	${RUN} ${_ULIMIT_CMD} \
		cd ${WRKSRC} && jbuilder build -j ${MAKE_JOBS:U1} \
		${JBUILDER_BUILD_FLAGS} -p ${JBUILDER_BUILD_PACKAGES:ts,} \
		${JBUILDER_BUILD_TARGETS}
.else
	${RUN} ${_ULIMIT_CMD} \
		cd ${WRKSRC} && jbuilder build -j ${MAKE_JOBS:U1} \
		${JBUILDER_BUILD_FLAGS} ${JBUILDER_BUILD_TARGETS}
.endif

.endif # jbuilder

#
# dune targets
#
.if ${OCAML_USE_DUNE} == "yes"

do-build:
.if !empty(DUNE_BUILD_PACKAGES)
	${RUN} ${_ULIMIT_CMD} \
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		dune build -j ${MAKE_JOBS:U1} \
		${DUNE_BUILD_FLAGS} -p ${DUNE_BUILD_PACKAGES:ts,} \
		${DUNE_BUILD_TARGETS}
.else
	${RUN} ${_ULIMIT_CMD} \
		cd ${WRKSRC} && dune build --profile release -j ${MAKE_JOBS:U1} \
		${DUNE_BUILD_FLAGS} ${DUNE_BUILD_TARGETS}
.endif

.endif # dune

# Add dependency on ocaml.
.include "../../lang/ocaml/buildlink3.mk"

.endif # OCAML_MK
