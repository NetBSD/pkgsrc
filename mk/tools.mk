# $NetBSD: tools.mk,v 1.4.2.2 2003/08/14 07:37:05 jlam Exp $
#
# handle platforms with broken tools in the base system, such as sed
# and awk.
#
# symlink the suitable versions of tools into .buildlink/bin (if they
# exist in the base system) and allow packages to force the use of
# pkgsrc GNU tools when they are not present in the base system by
# defining e.g. USE_GNU_TOOLS+="awk sed". version numbers are not
# considered.
#
# this functionality is buildlink2 only.
#
# packages should always use eg.
#
#	USE_GNU_TOOLS+=	grep
#
# to be sure not to override the setting passed by the user.
#

.if !defined(TOOLS_MK)
TOOLS_MK=	# defined

.if empty(USE_BUILDLINK2:M[nN][oO])
_TOOLS=		awk grep sed

# define which platforms already have GNU tools, so no need to pull in
# the pkgsrc versions.
_TOOLS_OPSYS_HAS_GNU.awk+=	FreeBSD-*-* Linux-*-* NetBSD-*-* OpenBSD-*-*
_TOOLS_OPSYS_HAS_GNU.grep+=	Darwin-*-* FreeBSD-*-* Linux-*-*
_TOOLS_OPSYS_HAS_GNU.grep+=	NetBSD-*-* OpenBSD-*-*
_TOOLS_OPSYS_HAS_GNU.sed+=	Linux-*-*

# where said tool is completely unusable, and no suitable replacement
# is available.
_TOOLS_OPSYS_INCOMPAT.awk+=	# empty
_TOOLS_OPSYS_INCOMPAT.grep+=	# empty
_TOOLS_OPSYS_INCOMPAT.sed+=	# empty

# a suitable alternative version is available in the base system, as
# eg. ${AWK}, ${SED}, ... refer to defs.*.mk for the definitions.
_TOOLS_REPLACE_OPSYS.awk+=	SunOS-*-*
_TOOLS_REPLACE_OPSYS.grep+=	SunOS-*-*
_TOOLS_REPLACE_OPSYS.sed+=	# empty

# what GNU tools did the package or user ask for, and does the OS
# already have it?
.for _tool_ in ${USE_GNU_TOOLS}
_TOOLS_NEED_GNU.${_tool_}=		YES
.  for _pattern_ in ${_TOOLS_OPSYS_HAS_GNU.${_tool_}}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_TOOLS_NEED_GNU.${_tool_}=		NO
.    endif
.  endfor
.endfor

# default to not requiring GNU tools.
.for _tool_ in ${_TOOLS}
_TOOLS_NEED_GNU.${_tool_}?=		NO
_TOOLS_REPLACE.${_tool_}?=		NO

# do we know it's broken?
.  for _pattern_ in ${_TOOLS_OPSYS_INCOMPAT.${_tool_}}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_TOOLS_NEED_GNU.${_tool_}=		YES
.    endif
.  endfor

# are we replacing it with a better version?
.  for _pattern_ in ${_TOOLS_REPLACE_OPSYS.${_tool_}}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_TOOLS_REPLACE.${_tool_}=		YES
.    endif
.  endfor

.endfor	# ${_TOOLS}

.if ${_TOOLS_NEED_GNU.awk} == "YES" && empty(PKGPATH:Mlang/gawk)
_TOOLS_PROGNAME.gawk=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}awk
# catch the case where we are in between package installs, thus don't
# have gawk available yet.
.  if exists(${_TOOLS_PROGNAME.gawk})
AWK=				${_TOOLS_PROGNAME.gawk}
.  endif
BUILDLINK_DEPENDS.gawk?=	gawk>=3.1.1
BUILDLINK_PKGSRCDIR.gawk?=	../../lang/gawk
BUILDLINK_DEPMETHOD.gawk?=	build
BUILDLINK_PACKAGES+=		gawk
BUILDLINK_PREFIX.gawk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gawk=		bin/${GNU_PROGRAM_PREFIX}awk
EVAL_PREFIX+=			BUILDLINK_PREFIX.gawk=gawk
.endif

.if ${_TOOLS_NEED_GNU.awk} == "YES" || ${_TOOLS_REPLACE.awk} == "YES"
BUILDLINK_TARGETS+=		gawk-buildlink gawk-buildlink-bin
.endif

.if ${_TOOLS_NEED_GNU.grep} == "YES" && empty(PKGPATH:Mtextproc/grep)
_TOOLS_PROGNAME.grep=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}grep
.  if exists(${_TOOLS_PROGNAME.grep})
GREP=				${_TOOLS_PROGNAME.grep}
.  endif
BUILDLINK_DEPENDS.grep?=	grep>=2.5.1
BUILDLINK_PKGSRCDIR.grep?=	../../textproc/grep
BUILDLINK_DEPMETHOD.grep?=	build
BUILDLINK_PACKAGES+=		grep
BUILDLINK_PREFIX.grep=		${LOCALBASE}
BUILDLINK_FILES.grep=		bin/${GNU_PROGRAM_PREFIX}grep
EVAL_PREFIX+=			BUILDLINK_PREFIX.grep=grep
.endif

.if ${_TOOLS_NEED_GNU.grep} == "YES" || ${_TOOLS_REPLACE.grep} == "YES"
BUILDLINK_TARGETS+=		grep-buildlink grep-buildlink-bin
.endif

.if ${_TOOLS_NEED_GNU.sed} == "YES" && empty(PKGPATH:Mtextproc/gsed)
_TOOLS_PROGNAME.gsed=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}sed
.  if exists(${_TOOLS_PROGNAME.gsed})
SED=				${_TOOLS_PROGNAME.gsed}
.  endif
BUILDLINK_DEPENDS.gsed?=	gsed>=3.0.2
BUILDLINK_PKGSRCDIR.gsed?=	../../textproc/gsed
BUILDLINK_DEPMETHOD.gsed?=	build
BUILDLINK_PACKAGES+=		gsed
BUILDLINK_PREFIX.gsed_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gsed=		bin/${GNU_PROGRAM_PREFIX}sed
EVAL_PREFIX+=			BUILDLINK_PREFIX.gsed=gsed
.endif

.if ${_TOOLS_NEED_GNU.sed} == "YES" || ${_TOOLS_REPLACE.sed} == "YES"
BUILDLINK_TARGETS+=		gsed-buildlink gsed-buildlink-bin
.endif

gawk-buildlink: _BUILDLINK_USE
gawk-buildlink-bin:
.if ${_TOOLS_NEED_GNU.awk} == "YES" && empty(PKGPATH:Mlang/gawk)
	${_PKG_SILENT}${_PKG_DEBUG}                              \
	[ ! -f ${BUILDLINK_DIR}/bin/awk ] &&                     \
	  ${LN} -fs ${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}awk    \
	  ${BUILDLINK_DIR}/bin/awk
.elif ${_TOOLS_REPLACE.awk} == "YES"
	${_PKG_SILENT}${_PKG_DEBUG}                              \
	[ ! -f ${BUILDLINK_DIR}/bin/awk ] &&                     \
	${LN} -fs ${AWK} ${BUILDLINK_DIR}/bin/awk
.endif

grep-buildlink: _BUILDLINK_USE
grep-buildlink-bin:
.if ${_TOOLS_NEED_GNU.grep} == "YES" && empty(PKGPATH:Mtextproc/grep)
	${_PKG_SILENT}${_PKG_DEBUG}                              \
	[ ! -f ${BUILDLINK_DIR}/bin/grep ] &&                    \
	  ${LN} -fs ${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}grep   \
	  ${BUILDLINK_DIR}/bin/grep
.elif ${_TOOLS_REPLACE.grep} == "YES"
	${_PKG_SILENT}${_PKG_DEBUG}                              \
	[ ! -f ${BUILDLINK_DIR}/bin/grep ] &&                    \
	${LN} -fs ${GREP} ${BUILDLINK_DIR}/bin/grep
.endif

gsed-buildlink: _BUILDLINK_USE
gsed-buildlink-bin:
.if ${_TOOLS_NEED_GNU.sed} == "YES" && empty(PKGPATH:Mtextproc/gsed)
	${_PKG_SILENT}${_PKG_DEBUG}                             \
	[ ! -f ${BUILDLINK_DIR}/bin/sed ] &&                    \
	  ${LN} -fs ${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}sed	\
	  ${BUILDLINK_DIR}/bin/sed
.elif ${_TOOLS_REPLACE.sed} == "YES"
	${_PKG_SILENT}${_PKG_DEBUG}                             \
	[ ! -f ${BUILDLINK_DIR}/bin/sed ] &&                    \
	${LN} -fs ${SED} ${BUILDLINK_DIR}/bin/sed
.endif

.endif	# USE_BUILDLINK2

.endif	# TOOLS_MK
