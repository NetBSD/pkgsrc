# $NetBSD: ocaml.mk,v 1.1 2014/08/17 09:25:23 jaapb Exp $
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
# OCAML_USE_OASIS
# package uses oasis infrastructure
# Set by this file:
# OCAML_SITELIBDIR

.if !defined(OCAML_MK)
OCAML_MK= # defined

.include "../../mk/bsd.fast.prefs.mk"

BUILD_DEFS+=	OCAML_USE_OPT_COMPILER

_VARGROUPS+=	ocaml
_PKG_VARS.ocaml=	\
	OCAML_USE_FINDLIB \
	OCAML_USE_OASIS
_DEF_VARS.ocaml=	\
	OCAML_USE_OPT_COMPILER
_SYS_VARS.ocaml=	\
	OCAML_SITELIBDIR

PKGNAME?=	ocaml-${DISTNAME}

# Default value of OCAML_USE_FINDLIB
OCAML_USE_FINDLIB?=	yes

# Default value of OCAML_USE_OASIS
OCAML_USE_OASIS?=	no

# Default value of OCAML_ENABLE_BINARY_COMPILER
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc") || \
    (${MACHINE_ARCH} == "arm")
OCAML_USE_OPT_COMPILER?=	yes
.else
OCAML_USE_OPT_COMPILER?=	no
.endif

# Value for OCAML_SITELIBDIR
OCAML_SITELIBDIR=	lib/ocaml/site-lib

.if ${OCAML_USE_FINDLIB} == "yes"
.include "../../devel/ocaml-findlib/buildlink3.mk"
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}
.endif

#
# Configure stuff for OASIS
#
.if ${OCAML_USE_OASIS} == "yes"
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--destdir "${DESTDIR}"
CONFIGURE_ARGS+=	--prefix "${PREFIX}"
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
		${SETENV} ${MAKE_ENV} ocaml setup.ml -build

# Redefine install target
do-install:
	${RUN} cd ${WRKSRC} && \
		ocaml setup.ml -install
.endif

# Add dependency to ocaml.
.include "../../lang/ocaml/buildlink3.mk"

.endif # OCAML_MK
