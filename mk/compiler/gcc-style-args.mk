# $NetBSD: gcc-style-args.mk,v 1.2 2023/07/30 18:57:44 nia Exp $

#
# Some compilers (e.g. clang) share command line argument formats with GCC.
#

_COMPILER_LD_FLAG=	-Wl,
_LINKER_RPATH_FLAG=	-R
_COMPILER_RPATH_FLAG=	${_COMPILER_LD_FLAG}${_LINKER_RPATH_FLAG}

_CTF_CFLAGS=		-gdwarf-2

# Newer compiler versions default to -fno-common, which causes lots of
# problems when compiling older code. Force -fno-common off until we're
# ready.
_WRAP_EXTRA_ARGS.cc+=	-fcommon
CWRAPPERS_PREPEND.cc+=	-fcommon

#
# Hardening features
#

# The user or package can choose the level of RELRO.
.if ${_PKGSRC_USE_RELRO} != "no"
.  if ${_PKGSRC_USE_RELRO} != "partial" && \
    ${RELRO_SUPPORTED:Uyes:tl} != "partial"
_RELRO_LDFLAGS=		-Wl,-zrelro -Wl,-znow
.  else
_RELRO_LDFLAGS=		-Wl,-zrelro
.  endif
.endif

.if !empty(_RELRO_LDFLAGS) && !empty(MACHINE_PLATFORM:MNetBSD-*-*mips*)
_RELRO_LDFLAGS+=	-Wl,-z,common-page-size=0x10000
.endif

# The user can choose the level of stack smashing protection.
.if empty(CC_VERSION:Mgcc-[1-3].*)
.  if ${PKGSRC_USE_SSP} == "all"
_SSP_CFLAGS=		-fstack-protector-all
.  elif ${PKGSRC_USE_SSP} == "strong"
_SSP_CFLAGS=		-fstack-protector-strong
.  else
_SSP_CFLAGS=		-fstack-protector
.  endif
.endif

# The user can choose the level of FORTIFY.
.if ${_PKGSRC_USE_FORTIFY} != "no"
.  if ${_PKGSRC_USE_FORTIFY} == "weak"
_FORTIFY_CFLAGS=	-D_FORTIFY_SOURCE=1
.  else
_FORTIFY_CFLAGS=	-D_FORTIFY_SOURCE=2
.  endif
.endif

.if ${_PKGSRC_MKREPRO} == "yes"
.export WRKDIR
# XXX the dollar sign should not be expanded by the shell
_MKREPRO_CFLAGS+=	-fdebug-prefix-map=$$$$WRKDIR/=
.endif

.if ${_PKGSRC_MKPIE} == "yes"
_MKPIE_CFLAGS=		-fPIC
# for libraries a sink wrapper around gcc is required and used instead
_MKPIE_LDFLAGS=		-pie
.endif
