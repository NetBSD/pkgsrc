# $NetBSD: autoconf.mk,v 1.5 2005/05/10 19:34:02 jlam Exp $
#
# This Makefile fragment handles packages that use GNU autoconf.
#
# By default, all of the autoconf-related scripts are marked as
# "missing" by running the GNU missing script in place of the utility.
# This hides the autoconf-related scripts from makefiles that aggressively
# call them when some of the inputs are modified in ways the makefiles
# don't expect.
#
# If a package needs to use GNU autoconf, then the package Makefile
# should contain one of the following lines:
#
#	USE_TOOLS+=	autoconf	# use recent GNU autoconf (>=2.50)
#	USE_TOOLS+=	autoconf213	# use GNU autoconf ~2.13
#
# This will allow the package to invoke "autoconf", "autoreconf", etc.
# by their usual, bare names.
#
# If a particular minimum version of autoconf is required, then the
# package Makefile can additionally set AUTOCONF_REQD to the desired
# version, e.g.:
#
#	AUTOCONF_REQD=	2.54	# use at least autoconf>=2.54
#
# To globally prevent any GNU autoconf handling, set the following
# in the package Makefile:
#
#	AUTOMAKE_OVERRIDE=	no
#

# Only allow one of "autoconf" and "autoconf213" in USE_TOOLS.
.if !empty(USE_TOOLS:Mautoconf) && !empty(USE_TOOLS:Mautoconf213)
PKG_FAIL_REASON+=	"\`\`autoconf'' and \`\`autoconf213'' conflict in USE_TOOLS."
.endif

# This is an exhaustive list of all of the scripts supplied by GNU
# autoconf.
#
_TOOLS_AUTOCONF=		autoconf autoheader autom4te autoreconf	\
				autoscan autoupdate ifnames

_TOOLS_AUTOCONF.autoconf=	autoconf	autoconf-2.13
_TOOLS_AUTOCONF.autoheader=	autoheader	autoheader-2.13	
_TOOLS_AUTOCONF.autom4te=	autom4te
_TOOLS_AUTOCONF.autoreconf=	autoreconf	autoreconf-2.13
_TOOLS_AUTOCONF.autoscan=	autoscan	autoscan-2.13
_TOOLS_AUTOCONF.autoupdate=	autoupdate	autoupdate-2.13
_TOOLS_AUTOCONF.ifnames=	ifnames		ifnames-2.13

_TOOLS_AUTOCONF_LINKS=	# empty

.if !defined(TOOLS_IGNORE.autoconf) && !empty(USE_TOOLS:Mautoconf)
.  if !empty(PKGPATH:Mdevel/autoconf)
MAKEFLAGS+=		TOOLS_IGNORE.autoconf=
.  else
AUTOCONF_REQD?=		2.50

TOOLS_DEPMETHOD.autoconf?=	BUILD_DEPENDS
TOOLS_DEPENDS.autoconf?=	autoconf>=${AUTOCONF_REQD}:../../devel/autoconf
.    if empty(${TOOLS_DEPMETHOD.autoconf}:M${TOOLS_DEPENDS.autoconf})
${TOOLS_DEPMETHOD.autoconf}+=	${TOOLS_DEPENDS.autoconf}
.    endif

_TOOLS_AUTOCONF_LINKS+=		autoconf
TOOLS_REAL_CMD.autoconf=	${LOCALBASE}/bin/autoconf

_TOOLS_AUTOCONF_LINKS+=		autoheader
TOOLS_REAL_CMD.autoheader=	${LOCALBASE}/bin/autoheader

_TOOLS_AUTOCONF_LINKS+=		autom4te
TOOLS_REAL_CMD.autom4te=	${LOCALBASE}/bin/autom4te

_TOOLS_AUTOCONF_LINKS+=		autoreconf
TOOLS_REAL_CMD.autoreconf=	${LOCALBASE}/bin/autoreconf

_TOOLS_AUTOCONF_LINKS+=		autoscan
TOOLS_REAL_CMD.autoscan=	${LOCALBASE}/bin/autoscan

_TOOLS_AUTOCONF_LINKS+=		autoupdate
TOOLS_REAL_CMD.autoupdate=	${LOCALBASE}/bin/autoupdate

_TOOLS_AUTOCONF_LINKS+=		ifnames
TOOLS_REAL_CMD.ifnames=		${LOCALBASE}/bin/ifnames

# Continue to define the following variables until packages have been
# taught to just use "autoconf", "autoheader", and "autoreconf" instead.
#
AUTOCONF=	${TOOLS_CMD.autoconf}
AUTOHEADER=	${TOOLS_CMD.autoheader}
AUTORECONF=	${TOOLS_CMD.autoreconf}
.  endif
.endif

.if !defined(TOOLS_IGNORE.autoconf213) && !empty(USE_TOOLS:Mautoconf213)
.  if !empty(PKGPATH:Mdevel/autoconf213)
MAKEFLAGS+=		TOOLS_IGNORE.autoconf213=
.  else
AUTOCONF_REQD?=		2.13

TOOLS_DEPMETHOD.autoconf213?=	BUILD_DEPENDS
TOOLS_DEPENDS.autoconf213?=	autoconf213>=${AUTOCONF_REQD}:../../devel/autoconf213
.    if empty(${TOOLS_DEPMETHOD.autoconf213}:M${TOOLS_DEPENDS.autoconf213})
${TOOLS_DEPMETHOD.autoconf213}+=	${TOOLS_DEPENDS.autoconf213}
.    endif

_TOOLS_AUTOCONF_LINKS+=		autoconf
TOOLS_REAL_CMD.autoconf=	${LOCALBASE}/bin/autoconf-2.13

_TOOLS_AUTOCONF_LINKS+=		autoheader
TOOLS_REAL_CMD.autoheader=	${LOCALBASE}/bin/autoheader-2.13

_TOOLS_AUTOCONF_LINKS+=		autoreconf
TOOLS_REAL_CMD.autoreconf=	${LOCALBASE}/bin/autoreconf-2.13

_TOOLS_AUTOCONF_LINKS+=		autoscan
TOOLS_REAL_CMD.autoscan=	${LOCALBASE}/bin/autoscan-2.13

_TOOLS_AUTOCONF_LINKS+=		autoupdate
TOOLS_REAL_CMD.autoupdate=	${LOCALBASE}/bin/autoupdate-2.13

_TOOLS_AUTOCONF_LINKS+=		ifnames
TOOLS_REAL_CMD.ifnames=		${LOCALBASE}/bin/ifnames-2.13

# Continue to define the following variables until packages have been
# taught to just use "autoconf", "autoheader", and "autoreconf" instead.
#
AUTOCONF=	${TOOLS_CMD.autoconf}
AUTOHEADER=	${TOOLS_CMD.autoheader}
AUTORECONF=	${TOOLS_CMD.autoreconf}

.    if defined(USE_LIBTOOL)
pre-configure: tools-libtool-m4-override
.    endif
.  endif
.endif

# For every script that hasn't already been symlinked, we mark it as
# "GNU missing".
#
AUTOMAKE_OVERRIDE?=	yes
.if !empty(AUTOMAKE_OVERRIDE:M[yY][eE][sS])
TOOLS_CREATE+=		${_TOOLS_AUTOCONF_LINKS}
.  for _t_ in ${_TOOLS_AUTOCONF_LINKS}
.    for _s_ in ${_TOOLS_AUTOCONF.${_t_}}
.      if empty(TOOLS_REAL_CMD.${_t_}:M*/${_s_})
TOOLS_GNU_MISSING+=	${_s_}
.      endif
.    endfor
.  endfor
.  for _t_ in ${_TOOLS_AUTOCONF}
.    if empty(_TOOLS_AUTOCONF_LINKS:M${_t_})
.      for _s_ in ${_TOOLS_AUTOCONF.${_t_}}
TOOLS_GNU_MISSING+=	${_s_}
.      endfor
.    endif
.  endfor
.  undef _s_
.  undef _t_
.endif

# LIBTOOL_M4_OVERRIDE lists the locations where the libtool.m4 symlink
# will be created.  The libtool.m4 symlink is only created if a GNU
# configure script exists at that location.
#
LIBTOOL_M4_OVERRIDE?=	libtool.m4 */libtool.m4 */*/libtool.m4

# Symlink the libtool-1.4.m4 file into any directory in which there's
# a configure script under ${WRKSRC}.  The symlink is called "libtool.m4",
# which is the name expected by the autoconf tools.  The symlinking
# is only done if we need autoconf-2.13 and libtool.  This allows
# autoconf-2.13, autoreconf-2.13 and aclocal-2.13 to use the older
# libtool.m4 file when regenerating files.  This is okay, because we
# later override the generated libtool file anyway.
#
.PHONY: tools-libtool-m4-override
tools-libtool-m4-override:
.for _pattern_ in ${LIBTOOL_M4_OVERRIDE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${WRKSRC};							\
	for cfile in ${_pattern_:S/libtool.m4$/configure/}; do		\
		if ${TEST} -f "$$cfile"; then				\
			libtool_m4=`${DIRNAME} $$cfile`/libtool.m4;	\
			${LN} -sf ${PKGSRCDIR}/mk/gnu-config/libtool-1.4.m4 \
				$$libtool_m4;				\
		fi;							\
	done
.endfor
.undef _pattern_
