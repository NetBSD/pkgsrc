# $NetBSD: tools.mk,v 1.34 2004/04/27 21:05:38 dmcmahill Exp $
#
# This Makefile creates a ${TOOLS_DIR} directory and populates the bin
# subdir with tools that hide the ones outside of ${TOOLS_DIR}.

.if !defined(TOOLS_MK)
TOOLS_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# Prepend ${TOOLS_DIR}/bin to the PATH so that our scripts are found
# first when searching for executables.
#
TOOLS_DIR=	${WRKDIR}/.tools
PREPEND_PATH+=	${TOOLS_DIR}/bin

TOOLS_SHELL?=		${SH}
_TOOLS_WRAP_LOG=	${WRKLOG}

.PHONY: do-tools
.if !target(do-tools)
do-tools: override-tools
.endif

.PHONY: override-tools
override-tools: # empty

# Create shell scripts in ${TOOLS_DIR}/bin that simply return an error
# status for each of the GNU auto* tools, which should cause GNU configure
# scripts to think that they can't be found.
#
AUTOMAKE_OVERRIDE?=	yes
_GNU_MISSING=		${.CURDIR}/../../mk/gnu-config/missing
_HIDE_PROGS.autoconf=	bin/autoconf	bin/autoconf-2.13		\
			bin/autoheader	bin/autoheader-2.13		\
			bin/autom4te					\
			bin/autoreconf	bin/autoreconf-2.13		\
			bin/autoscan	bin/autoscan-2.13		\
			bin/autoupdate	bin/autoupdate-2.13		\
			bin/ifnames	bin/ifnames-2.13
_HIDE_PROGS.automake=	bin/aclocal	bin/aclocal-1.4			\
					bin/aclocal-1.5			\
					bin/aclocal-1.6			\
					bin/aclocal-1.7			\
					bin/aclocal-1.8			\
			bin/automake	bin/automake-1.4		\
					bin/automake-1.5		\
					bin/automake-1.6		\
					bin/automake-1.7		\
					bin/automake-1.8

.if empty(AUTOMAKE_OVERRIDE:M[nN][oO])
_CONFIGURE_PREREQ+=	override-autotools
.PHONY: override-autotools
.  for _autotool_ in autoconf automake
.    for _prog_ in ${_HIDE_PROGS.${_autotool_}}
override-autotools: ${TOOLS_DIR}/${_prog_}
${TOOLS_DIR}/${_prog_}: ${_GNU_MISSING}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} '#!${TOOLS_SHELL}';				\
	  ${ECHO} 'exec ${_GNU_MISSING} ${_prog_:T:C/-[0-9].*$//}'	\
	) > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.    endfor
.  endfor
.endif	# AUTOMAKE_OVERRIDE != NO

# Create an install-info script that is a "no operation" command,
# as registration of info files is handled by the INSTALL script.
#
CONFIGURE_ENV+=	INSTALL_INFO="${TOOLS_DIR}/bin/install-info"
MAKE_ENV+=	INSTALL_INFO="${TOOLS_DIR}/bin/install-info"

override-tools: ${TOOLS_DIR}/bin/install-info
${TOOLS_DIR}/bin/install-info:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} '#!${TOOLS_SHELL}';				\
	  ${ECHO} 'wrapperlog="$${TOOLS_WRAPPER_LOG-${_TOOLS_WRAP_LOG}}"'; \
	  ${ECHO} '${ECHO} "==> No-op install-info $$*" >> $$wrapperlog' \
	) > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}

# Create a makeinfo script that will invoke the right makeinfo
# command if USE_MAKEINFO is 'yes' or will exit on error if not.
#
CONFIGURE_ENV+=	MAKEINFO="${TOOLS_DIR}/bin/makeinfo"
MAKE_ENV+=	MAKEINFO="${TOOLS_DIR}/bin/makeinfo"

override-tools: ${TOOLS_DIR}/bin/makeinfo
.if empty(USE_MAKEINFO:M[nN][oO])
${TOOLS_DIR}/bin/makeinfo:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} "#!${TOOLS_SHELL}";				\
	  ${ECHO} 'wrapperlog="$${TOOLS_WRAPPER_LOG-${_TOOLS_WRAP_LOG}}"'; \
	  ${ECHO} '${ECHO} "${MAKEINFO} $$*" >> $$wrapperlog';		\
	  ${ECHO} 'exec ${MAKEINFO} "$$@"'				\
	) > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.else # !USE_MAKEINFO
${TOOLS_DIR}/bin/makeinfo: ${_GNU_MISSING}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} "#!${TOOLS_SHELL}";				\
	  ${ECHO} 'wrapperlog="$${TOOLS_WRAPPER_LOG-${_TOOLS_WRAP_LOG}}"'; \
	  ${ECHO} '${ECHO} "==> Error: makeinfo $$*" >> $$wrapperlog';	\
	  ${ECHO} 'exit 1'						\
	) >  ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.endif # USE_MAKEINFO

# Handle platforms with broken tools in the base system, e.g. sed, awk.
#
# Symlink the suitable versions of tools into ${TOOLS_DIR}/bin (if they
# exist in the base system) and allow packages to force the use of
# pkgsrc GNU tools when they are not present in the base system by
# defining e.g. USE_GNU_TOOLS+="awk sed".  Version numbers are not
# considered.

_TOOLS=		awk grep lex m4 make patch sed yacc

.if defined(_IGNORE_USE_GNU_TOOLS)
USE_GNU_TOOLS:=		# empty
.else
USE_GNU_TOOLS?=		# empty
.endif

# These platforms already have GNU versions of the tools in the base
# system, so no need to pull in the pkgsrc versions; we will use these
# instead.
#
_TOOLS_OPSYS_HAS_GNU.awk+=	FreeBSD-*-* Interix-*-* Linux-*-* NetBSD-*-*
_TOOLS_OPSYS_HAS_GNU.awk+=	OpenBSD-*-*
_TOOLS_OPSYS_HAS_GNU.grep+=	Darwin-*-* FreeBSD-*-* Linux-*-*
_TOOLS_OPSYS_HAS_GNU.grep+=	NetBSD-*-* OpenBSD-*-*
_TOOLS_OPSYS_HAS_GNU.lex+=	FreeBSD-*-* Interix-*-* Linux-*-* NetBSD-*-*
_TOOLS_OPSYS_HAS_GNU.lex+=	OpenBSD-*-*
_TOOLS_OPSYS_HAS_GNU.m4+=	# empty
_TOOLS_OPSYS_HAS_GNU.make+=	Darwin-*-*
_TOOLS_OPSYS_HAS_GNU.patch+=	Darwin-*-* FreeBSD-*-* Linux-*-*
_TOOLS_OPSYS_HAS_GNU.patch+=	NetBSD-*-* OpenBSD-*-*
_TOOLS_OPSYS_HAS_GNU.sed+=	FreeBSD-*-* Linux-*-* NetBSD-*-*
_TOOLS_OPSYS_HAS_GNU.yacc+=	Linux-*-*

# These platforms have GNUish versions of the tools available in the base
# system, which we already define as ${AWK}, ${SED}, etc. (refer to
# defs.*.mk for the definitions), so no need to pull in the pkgsrc
# versions; we will use these instead.
#
_TOOLS_REPLACE_OPSYS.awk+=	SunOS-*-*
_TOOLS_REPLACE_OPSYS.grep+=	SunOS-*-*
_TOOLS_REPLACE_OPSYS.lex+=	# empty
_TOOLS_REPLACE_OPSYS.m4+=	# empty
_TOOLS_REPLACE_OPSYS.make+=	# empty
_TOOLS_REPLACE_OPSYS.patch+=	SunOS-*-*
_TOOLS_REPLACE_OPSYS.sed+=	SunOS-*-*
_TOOLS_REPLACE_OPSYS.yacc+=	# empty

# These platforms have completely unusable versions of these tools, and
# no suitable replacement is available.
#
_TOOLS_OPSYS_INCOMPAT.awk+=	IRIX-*-*
_TOOLS_OPSYS_INCOMPAT.grep+=	# empty
_TOOLS_OPSYS_INCOMPAT.lex+=	# empty
_TOOLS_OPSYS_INCOMPAT.m4+=	# empty
_TOOLS_OPSYS_INCOMPAT.make+=	# empty
_TOOLS_OPSYS_INCOMPAT.patch+=	# empty
_TOOLS_OPSYS_INCOMPAT.sed+=	# empty
_TOOLS_OPSYS_INCOMPAT.yacc+=	# empty

# Default to not requiring GNU tools.
.for _tool_ in ${_TOOLS}
_TOOLS_NEED_GNU.${_tool_}?=	NO
_TOOLS_REPLACE.${_tool_}?=	NO
_TOOLS_OVERRIDE.${_tool_}?=	NO
.endfor

.for _tool_ in ${USE_GNU_TOOLS}
#
# What GNU tools did the package or user ask for, and does the base
# system already have it?
#
_TOOLS_NEED_GNU.${_tool_}=	YES
.  for _pattern_ in ${_TOOLS_OPSYS_HAS_GNU.${_tool_}}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_TOOLS_NEED_GNU.${_tool_}=	NO
.    endif
.  endfor
#
# Do we know the base system tool is broken?
#
.  for _pattern_ in ${_TOOLS_OPSYS_INCOMPAT.${_tool_}}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_TOOLS_NEED_GNU.${_tool_}=	YES
.    endif
.  endfor
.endfor	# USE_GNU_TOOLS
#
# Are we using a GNUish system tool in place of the needed GNU tool?
#
.for _tool_ in ${_TOOLS}
.  for _pattern_ in ${_TOOLS_REPLACE_OPSYS.${_tool_}}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_TOOLS_REPLACE.${_tool_}=	YES
.    endif
.  endfor
.endfor	_TOOLS

.if ${_TOOLS_REPLACE.awk} == "YES"
_TOOLS_OVERRIDE.awk=	YES
_TOOLS_PROGNAME.awk=	${AWK}
.endif
.if (${_TOOLS_NEED_GNU.awk} == "YES") && empty(PKGPATH:Mlang/gawk)
BUILD_DEPENDS+=		gawk>=3.1.1:../../lang/gawk
_TOOLS_OVERRIDE.awk=	YES
_TOOLS_PROGNAME.awk=	${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}awk
.  if exists(${_TOOLS_PROGNAME.awk})
AWK:=			${_TOOLS_PROGNAME.awk}
.  endif
.endif
.if !empty(PKGPATH:Mlang/gawk)
_TOOLS_OVERRIDE.awk=	NO
MAKEFLAGS+=		_IGNORE_USE_GNU_TOOLS=
.endif

.if ${_TOOLS_REPLACE.grep} == "YES"
_TOOLS_OVERRIDE.grep=	YES
_TOOLS_PROGNAME.grep=	${GREP}
.endif
.if (${_TOOLS_NEED_GNU.grep} == "YES") && empty(PKGPATH:Mtextproc/grep)
BUILD_DEPENDS+=		grep>=2.5.1:../../textproc/grep
_TOOLS_OVERRIDE.grep=	YES
_TOOLS_PROGNAME.grep=	${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}grep
.  if exists(${_TOOLS_PROGNAME.grep})
GREP:=			${_TOOLS_PROGNAME.grep}
.  endif
.endif
.if !empty(PKGPATH:Mtextproc/grep)
_TOOLS_OVERRIDE.grep=	NO
MAKEFLAGS+=		_IGNORE_USE_GNU_TOOLS=
.endif

.if ${_TOOLS_REPLACE.lex} == "YES"
_TOOLS_OVERRIDE.lex=	YES
_TOOLS_PROGNAME.lex=	${LEX}
.endif
.if (${_TOOLS_NEED_GNU.lex} == "YES") && empty(PKGPATH:Mdevel/flex)
.if defined(USE_BUILDLINK3) && empty(USE_BUILDLINK3:M[nN][oO])
.include "../../devel/flex/buildlink3.mk"
.else
BUILD_DEPENDS+=		flex>=2.5:../../devel/flex
.endif
_TOOLS_OVERRIDE.lex=	YES
_TOOLS_PROGNAME.lex=	${LOCALBASE}/bin/flex
.  if exists(${_TOOLS_PROGNAME.lex})
LEX:=			${_TOOLS_PROGNAME.lex}
.  endif
.endif
.if !empty(PKGPATH:Mdevel/flex)
_TOOLS_OVERRIDE.lex=	NO
MAKEFLAGS+=		_IGNORE_USE_GNU_TOOLS=
.endif

.if ${_TOOLS_REPLACE.m4} == "YES"
_TOOLS_OVERRIDE.m4=	YES
_TOOLS_PROGNAME.m4=	${M4}
.endif
.if (${_TOOLS_NEED_GNU.m4} == "YES") && empty(PKGPATH:Mdevel/m4)
BUILD_DEPENDS+=		m4>=1.4:../../devel/m4
_TOOLS_OVERRIDE.m4=	YES
_TOOLS_PROGNAME.m4=	${LOCALBASE}/bin/gm4	# "gm4" always exists
.  if exists(${_TOOLS_PROGNAME.m4})
M4:=			${_TOOLS_PROGNAME.m4}
.  endif
.endif
.if !empty(PKGPATH:Mdevel/m4)
_TOOLS_OVERRIDE.m4=	NO
MAKEFLAGS+=		_IGNORE_USE_GNU_TOOLS=
.endif

.if ${_TOOLS_REPLACE.make} == "YES"
_TOOLS_OVERRIDE.make=	YES
_TOOLS_PROGNAME.make=	${GMAKE}
.endif
.if (${_TOOLS_NEED_GNU.make} == "YES") && empty(PKGPATH:Mdevel/gmake)
BUILD_DEPENDS+=		gmake>=3.78:../../devel/gmake
_TOOLS_OVERRIDE.make=	YES
_TOOLS_PROGNAME.make=	${LOCALBASE}/bin/gmake	# "gmake" always exists
.  if exists(${_TOOLS_PROGNAME.make})
GMAKE:=			${_TOOLS_PROGNAME.make}
.  endif
.endif
.if !empty(PKGPATH:Mdevel/gmake)
_TOOLS_OVERRIDE.make=	NO
MAKEFLAGS+=		_IGNORE_USE_GNU_TOOLS=
.endif

.if ${_TOOLS_REPLACE.patch} == "YES"
_TOOLS_OVERRIDE.patch=	YES
_TOOLS_PROGNAME.patch=	${PATCH}
.endif
.if (${_TOOLS_NEED_GNU.patch} == "YES") && empty(PKGPATH:Mdevel/patch)
BUILD_DEPENDS+=		patch>=2.2:../../devel/patch
_TOOLS_OVERRIDE.patch=	YES
_TOOLS_PROGNAME.patch=	${LOCALBASE}/bin/gpatch	# "gpatch" always exists
.  if exists(${_TOOLS_PROGNAME.patch})
PATCH:=			${_TOOLS_PROGNAME.patch}
.  endif
.endif
.if !empty(PKGPATH:Mdevel/patch)
_TOOLS_OVERRIDE.patch=	NO
MAKEFLAGS+=		_IGNORE_USE_GNU_TOOLS=
.endif

.if ${_TOOLS_REPLACE.sed} == "YES"
_TOOLS_OVERRIDE.sed=	YES
_TOOLS_PROGNAME.sed=	${SED}
.endif
.if (${_TOOLS_NEED_GNU.sed} == "YES") && empty(PKGPATH:Mtextproc/gsed)
BUILD_DEPENDS+=		gsed>=3.0.2:../../textproc/gsed
_TOOLS_OVERRIDE.sed=	YES
_TOOLS_PROGNAME.sed=	${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}sed
.  if exists(${_TOOLS_PROGNAME.sed})
SED:=			${_TOOLS_PROGNAME.sed}
.  endif
.endif
.if !empty(PKGPATH:Mtextproc/gsed)
_TOOLS_OVERRIDE.sed=	NO
MAKEFLAGS+=		_IGNORE_USE_GNU_TOOLS=
.endif

.if ${_TOOLS_REPLACE.yacc} == "YES"
_TOOLS_OVERRIDE.yacc=	YES
_TOOLS_PROGNAME.yacc=	${YACC}
.endif
.if (${_TOOLS_NEED_GNU.yacc} == "YES") && empty(PKGPATH:Mdevel/bison)
BUILD_DEPENDS+=		bison>=1.0:../../devel/bison
_TOOLS_OVERRIDE.yacc=	YES
_TOOLS_PROGNAME.yacc=	${LOCALBASE}/bin/bison
.  if exists(${_TOOLS_PROGNAME.yacc})
YACC:=			${_TOOLS_PROGNAME.yacc} -y
.  endif
.endif
.if !empty(PKGPATH:Mdevel/yacc)
_TOOLS_OVERRIDE.yacc=	NO
MAKEFLAGS+=		_IGNORE_USE_GNU_TOOLS=
.endif

# If _TOOLS_OVERRIDE.<tool> is actually set to "YES", then we override
# the tool with the one specified in _TOOLS_PROGNAME.<tool>.
#
.for _tool_ in ${_TOOLS}
.  if ${_TOOLS_OVERRIDE.${_tool_}} == "YES"
override-tools: ${TOOLS_DIR}/bin/${_tool_}

${TOOLS_DIR}/bin/${_tool_}:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	src="${_TOOLS_PROGNAME.${_tool_}}";				\
	if [ -x $$src -a ! -f ${.TARGET} ]; then			\
		${MKDIR} ${.TARGET:H};					\
		${LN} -sf $$src ${.TARGET};				\
	fi
.  endif
.endfor

# Always provide a symlink from ${TOOLS_DIR}/bin/make to the "make"
# used to build the package.  The following only creates the symlink
# if GNU make isn't required (and already symlinked from above).
#
override-tools: ${TOOLS_DIR}/bin/make

.if !target(${TOOLS_DIR}/bin/make)
${TOOLS_DIR}/bin/make:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	case ${MAKE_PROGRAM} in						\
	/*)	src="${MAKE_PROGRAM}" ;;				\
	*)	src=`${TYPE} ${MAKE_PROGRAM} | ${AWK} '{ print $$NF }'` ;; \
	esac;								\
	if [ -x $$src -a ! -f ${.TARGET} ]; then			\
		${MKDIR} ${.TARGET:H};					\
		${LN} -sf $$src ${.TARGET};				\
	fi
.endif

.endif	# TOOLS_MK
