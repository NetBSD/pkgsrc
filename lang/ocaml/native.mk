# $NetBSD: native.mk,v 1.1 2022/05/24 18:25:38 jaapb Exp $
#
# This Makefile fragment handles the native code compiler options for OCaml.
# It is used by ocaml.mk and the lang/ocaml package.
#
# Build def variables:
# OCAML_USE_OPT_COMPILER
# if set to yes, will enable optimised (native code) compilation
# default value: depends on architecture
#
# PLIST variable:
# PLIST.ocaml-opt for files only installed when using the optimised compiler
# Set based on OCAML_USE_OPT_COMPILER

.if !defined(OCAML_NATIVE_MK)
OCAML_NATIVE_MK=	# defined

.include "../../mk/bsd.fast.prefs.mk"

BUILD_DEFS+=	OCAML_USE_OPT_COMPILER

_VARGROUPS+=	ocaml
_DEF_VARS.ocaml=	\
	OCAML_USE_OPT_COMPILER

# Default value of OCAML_USE_OPT_COMPILER
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
     !empty(MACHINE_ARCH:M*arm*) || (${MACHINE_ARCH} == "aarch64") || \
     (${MACHINE_ARCH} == "aarch64eb") || (${MACHINE_ARCH} == "x86_64")
OCAML_USE_OPT_COMPILER?=	yes
.else
OCAML_USE_OPT_COMPILER?=	no
.endif

# Things that get installed with the opt compiler
PLIST_VARS+=	ocaml-opt

.if ${OCAML_USE_OPT_COMPILER} == "yes"
# The opt compiler needs the C compiler suite
USE_LANGUAGES+=		c
PLIST.ocaml-opt=	yes
.else
# If we're bytecode compiling, don't strip executables
INSTALL_UNSTRIPPED=	yes
.endif

.endif # OCAML_NATIVE_MK
