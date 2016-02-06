# $NetBSD: ocaml.mk,v 1.5 2016/02/06 12:10:34 jaapb Exp $
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
# OCAML_USE_OASIS [implies OCAML_USE_FINDLIB]
# package uses oasis infrastructure
# OCAML_USE_OPAM
# package uses OPAM
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
	OCAML_USE_OASIS \
	OCAML_USE_OPAM \
	OCAML_BUILD_ARGS
_DEF_VARS.ocaml=	\
	OCAML_USE_OPT_COMPILER
_SYS_VARS.ocaml=	\
	OCAML_SITELIBDIR

# Default value of OCAML_USE_FINDLIB
OCAML_USE_FINDLIB?=	no

# Default value of OCAML_USE_OASIS
OCAML_USE_OASIS?=	no

# Default value of OCAML_USE_OPAM
OCAML_USE_OPAM?= no

# Default value of OASIS_BUILD_ARGS
OASIS_BUILD_ARGS?=	# empty

# Default value of OCAML_ENABLE_BINARY_COMPILER
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc") || \
    (${MACHINE_ARCH} == "arm")
OCAML_USE_OPT_COMPILER?=	yes
.else
OCAML_USE_OPT_COMPILER?=	no
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
.endif

#
# OASIS targets
#
.if ${OCAML_USE_OASIS} == "yes"
# Redefine configure target
do-configure:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ocaml setup.ml -configure ${CONFIGURE_ARGS}

# Redefine build target
do-build:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ocaml setup.ml -build ${OASIS_BUILD_ARGS}

# Redefine install target
do-install:
	${RUN} cd ${WRKSRC} && \
		ocaml setup.ml -install
.endif

# Add dependency to ocaml.
.include "../../lang/ocaml/buildlink3.mk"

.endif # OCAML_MK
