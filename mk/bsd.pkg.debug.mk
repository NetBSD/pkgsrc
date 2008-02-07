# $NetBSD: bsd.pkg.debug.mk,v 1.21 2008/02/07 21:36:13 rillig Exp $
#
# Public targets:
#
# debug:
#	outputs the values of some commonly used variables and the
#	contents of some files which are useful for tracking bugs,
#	especially for packages that use the GNU autotools.
#

PRINTF?=	printf

# Note: In the many cases where ${x} is used, the quoting is left out
# intentionally, since x is an element of a list of shell words, and
# passing such a shell word to the shell should still result in one
# word. That way, no extra level of quoting is introduced.
#
# The only exception is the "<" character in CONFIGURE_ARGS, where it
# is often used to redirect the input coming from another source. That
# character has to be quoted.

.PHONY: \
	debug \
	_show-dbginfo-file-versions \
	_show-dbginfo-tools \
	_show-dbginfo-configure \
	_show-dbginfo-config.status \
	_show-dbginfo-config.h \
	_show-dbginfo-build \
	_show-dbginfo-install \
	_show-dbginfo-plist-subst

debug: \
	_show-dbginfo-file-versions \
	_show-dbginfo-tools \
	_show-dbginfo-configure \
	_show-dbginfo-config.status \
	_show-dbginfo-config.h \
	_show-dbginfo-build \
	_show-dbginfo-install \
	_show-dbginfo-plist-subst

_show-dbginfo-file-versions:
	@${PRINTF} "File versions:\\n"
	${RUN} \
	sedexpr='s,^.*\([$$]NetBSD:[^$$]*\$$\).*,\1,p';			\
	${FIND} * -type f -print					\
	| while read fname; do						\
	  ident=`${SED} -n						\
	    -e 's,^.*\\([$$]NetBSD:[^$$]*\\$$\\).*,\\1,p'		\
	    -e 's,^.*\\([$$]Id:[^$$]*\\$$\\).*,\\1,p'			\
	    "$${fname}" | ${SED} 1q` || continue;			\
	  case $${ident} in						\
	  *?*) ${PRINTF} "\\t%s: %s\\n" "$${fname}" "$${ident}";;	\
	  esac;								\
	done
	@${PRINTF} "\\n"

_show-dbginfo-tools:
	@${PRINTF} "TOOLS:\\n"
	@${USE_TOOLS:C/:.*//:O:u:@t@${_TOOLS_VARNAME.${t}:D${PRINTF} "\\t%s=%s\\n" ${_TOOLS_VARNAME.${t}} ${${_TOOLS_VARNAME.${t}}:Q};}@}
	@${PRINTF} "\\n"

_show-dbginfo-configure:
	@${PRINTF} "CONFIGURE_DIRS:\\n"; ${CONFIGURE_DIRS:@x@${PRINTF} "\\t%s\\n" ${x};@}
	@${PRINTF} "\\n"
	@${PRINTF} "CONFIGURE_ENV (sorted alphabetically):\\n"; ${CONFIGURE_ENV:O:@x@${PRINTF} "\\t%s\\n" ${x};@}
	@${PRINTF} "\\n"
	@${PRINTF} "CONFIGURE_SCRIPT:\\n\\t%s\\n" ${CONFIGURE_SCRIPT}
	@${PRINTF} "\\n"
	@${PRINTF} "CONFIGURE_ARGS:\\n"; ${CONFIGURE_ARGS:@x@${PRINTF} "\\t%s\\n" ${x:S,<,\<,};@}
	@${PRINTF} "\\n"

_show-dbginfo-config.status:
.if !empty(CONFIGURE_DIRS:M*)
	${RUN} \
	if ${TEST} -d ${WRKSRC:Q}; then cd ${WRKSRC:Q};			\
	for cs in ${CONFIGURE_DIRS:=/config.status}; do			\
	  if ${TEST} ! -f "$${cs}"; then continue; fi;			\
	  ${PRINTF} "%s:\\n" "$${cs}";					\
	  ${SED} -n -e 's,|#_!!_#|,,g'					\
		-e '/s,^\\(\[	#\]\*\\)/d'				\
		-e 's:^s,@\([^@]*\)@,\(.*\),;t t$$:	\1=\2:p'	\
		-e 's:^s&@\([^@]*\)@&\(.*\)&;t t$$:	\1=\2:p'	\
		-e 's:^s,@\([^@]*\)@,\(.*\),g$$:	\1=\2:p'	\
		-e 's:^s%@\([^@]*\)@%\(.*\)%g$$:	\1=\2:p'	\
		-e 's:^s&@\([^@]*\)@&\(.*\)&g$$:	\1=\2:p'	\
		-e 's:^\(s[^[:alnum:]].*\):	&:p'			\
		-e '/:\[FHLC\]/q'					\
		    "$${cs}"						\
	  | ${SORT};							\
	  ${PRINTF} "\\n";						\
	done; fi
.else
	@${DO_NADA}
.endif

_show-dbginfo-config.h:
.if !empty(CONFIGURE_DIRS:M*)
	${RUN} \
	[ -d ${WRKSRC} ] || exit 0;					\
	print_config_h() {						\
	  printf "%s:\\n" "`pwd`/$$1";					\
	  awk '/^#define / { print "\t"$$0; } /^\/\* #undef / { print "\t" $$2 " " $$3; }' < "$$1"; \
	  printf "\\n";							\
	};								\
	for cdir in ${CONFIGURE_DIRS}; do				\
	  cd ${WRKSRC}; [ -d "$$cdir" ] || continue; cd "$$cdir";	\
	  [ ! -f config.h ] || { print_config_h config.h; continue; };	\
	  [ ! -f config.status ] || {					\
	    : "autoconf 2.59";						\
	    chs=`sed -n 's,^config_headers="\([^:]*\).*".*,\1,p' config.status || true`; \
	    : "autoconf 2.13";						\
	    [ "$$chs" ] || chs=`sed -n 's,^  CONFIG_HEADERS="\([^:"]*\).*,\1,p' config.status || true`; \
	    done=no;							\
	    for ch in $$chs; do print_config_h "$$ch"; done=yes; done;	\
	    [ $$done = no ] || continue;				\
	  };								\
	  printf "WARNING: No config header found in `pwd`.\\n\\n";	\
	done
.else
	@${DO_NADA}
.endif

_show-dbginfo-build:
	@${PRINTF} "PKGSRC_MAKE_ENV (sorted alphabetically):\\n"; ${PKGSRC_MAKE_ENV:O:@x@${PRINTF} "\\t%s\\n" ${x};@}
	@${PRINTF} "\\n"
	@${PRINTF} "BUILD_DIRS:\\n"; ${BUILD_DIRS:@x@${PRINTF} "\\t%s\\n" ${x};@}
	@${PRINTF} "\\n"
	@${PRINTF} "MAKE_ENV (sorted alphabetically):\\n"; ${MAKE_ENV:O:@x@${PRINTF} "\\t%s\\n" ${x};@}
	@${PRINTF} "\\n"
	@${PRINTF} "MAKE_PROGRAM:\\n\\t%s\\n" ${MAKE_PROGRAM:Q}
	@${PRINTF} "\\n"
	@${PRINTF} "MAKE_FLAGS:\\n"; ${MAKE_FLAGS:@x@${PRINTF} "\\t%s\\n" ${x};@}
	@${PRINTF} "\\n"
	@${PRINTF} "BUILD_MAKE_FLAGS:\\n"; ${BUILD_MAKE_FLAGS:@x@${PRINTF} "\\t%s\\n" ${x};@}
	@${PRINTF} "\\n"

_show-dbginfo-install:
	@${PRINTF} "INSTALL_DIRS:\\n"; ${INSTALL_DIRS:@x@${PRINTF} "\\t%s\\n" ${x};@}
	@${PRINTF} "\\n"
	@${PRINTF} "INSTALL_MAKE_FLAGS:\\n"; ${INSTALL_MAKE_FLAGS:@x@${PRINTF} "\\t%s\\n" ${x};@}
	@${PRINTF} "\\n"

_show-dbginfo-plist-subst:
	@${PRINTF} "PLIST_SUBST (sorted alphabetically):\\n"; ${PLIST_SUBST:O:@x@${PRINTF} "\\t%s\\n" ${x};@}
	@${PRINTF} "\\n"
