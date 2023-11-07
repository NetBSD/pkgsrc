# $NetBSD: gnu-configure.mk,v 1.30 2023/11/07 13:19:47 nia Exp $
#
# Package-settable variables:
#
# GNU_CONFIGURE
#	Whether the package has a GNU-style configure script as the
#	primary means of configuring itself to the platform.
#
#	Possible: yes no
#	Default: undefined
#
# GNU_CONFIGURE_QUIET
#	When set to "yes", runs the configure scripts in quiet mode,
#	which does not print the typical "checking for ...".
#
#	By omitting these, any accidental output or other error messages
#	are more easily visible in the log.  This can help find
#	unportable use of tools like sed, awk, test.
#
# GNU_CONFIGURE_STRICT
#	Whether unknown --enable/--disable/--with/--without options make
#	the package fail immediately.
#
#	Command line options that are unknown for all configure scripts
#	of a package are effectively ignored and should be replaced with
#	their current equivalent (in case they have been renamed), or
#	otherwise be removed.
#
#	Possible: yes no warn
#	Default: no
#	See also: configure-help show-unknown-configure-options
#
# Keywords: configure configure_args gnu strict enable disable

_VARGROUPS+=			gnu-configure
_USER_VARS.gnu-configure=	# none
_PKG_VARS.gnu-configure=	\
	GNU_CONFIGURE GNU_CONFIGURE_STRICT GNU_CONFIGURE_PREFIX \
	SET_LIBDIR GNU_CONFIGURE_LIBSUBDIR \
	GNU_CONFIGURE_LIBDIR GNU_CONFIGURE_INFODIR GNU_CONFIGURE_MANDIR \
	CONFIGURE_HAS_LIBDIR CONFIGURE_HAS_MANDIR CONFIGURE_HAS_INFODIR \
	OVERRIDE_DIRDEPTH.configure \
	USE_GNU_CONFIGURE_HOST

HAS_CONFIGURE=			defined
OVERRIDE_GNU_CONFIG_SCRIPTS=	defined
INSTALL_SH_OVERRIDE?=		# empty

CONFIGURE_ENV+=	CONFIG_SHELL=${CONFIG_SHELL:Q}
CONFIGURE_ENV+=	LIBS=${LIBS:M*:Q}
CONFIGURE_ENV+=	ac_given_INSTALL=${INSTALL:Q}\ -c\ -o\ ${BINOWN}\ -g\ ${BINGRP}

.if (defined(USE_LIBTOOL) || !empty(PKGPATH:Mdevel/libtool-base)) && \
    defined(_OPSYS_MAX_CMDLEN_CMD)
CONFIGURE_ENV+=	lt_cv_sys_max_cmd_len=${_OPSYS_MAX_CMDLEN_CMD:sh}
.endif

.if ${OPSYS} == "MirBSD"
CONFIGURE_ENV+=	lt_cv_deplibs_check_method='match_pattern /lib[^/]+(\.so\.[0-9]+\.[0-9]+|\.so|_pic\.a)$$'
.endif

.if ${MACHINE_PLATFORM:MDarwin-[0-8].*-powerpc}
# ld does not have -rpath
CONFIGURE_ARGS+=	--disable-rpath
.endif

GNU_CONFIGURE_PREFIX?=	${PREFIX}
CONFIGURE_ARGS+=	--prefix=${GNU_CONFIGURE_PREFIX:Q}

.if (defined(SET_LIBDIR) && !empty(SET_LIBDIR)) || \
	(defined(GNU_CONFIGURE_LIBDIR) && !empty(GNU_CONFIGURE_LIBDIR)) || \
	(defined(GNU_CONFIGURE_LIBSUBDIR) && !empty(GNU_CONFIGURE_LIBSUBDIR))
CONFIGURE_HAS_LIBDIR=	yes
.else
CONFIGURE_HAS_LIBDIR?=	no
.endif
.if defined(GNU_CONFIGURE_LIBSUBDIR) && !empty(GNU_CONFIGURE_LIBSUBDIR)
GNU_CONFIGURE_LIBDIR?=	${GNU_CONFIGURE_PREFIX}/lib/${GNU_CONFIGURE_LIBSUBDIR}
.else
GNU_CONFIGURE_LIBDIR?=	${GNU_CONFIGURE_PREFIX}/lib
.endif
.if !empty(CONFIGURE_HAS_LIBDIR:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--libdir=${GNU_CONFIGURE_LIBDIR}
.endif

USE_GNU_CONFIGURE_HOST?=	yes
.if !empty(USE_GNU_CONFIGURE_HOST:M[yY][eE][sS])
.  if !empty(TOOLS_USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ARGS+=	--build=${NATIVE_MACHINE_GNU_PLATFORM:Q}
.  else
CONFIGURE_ARGS+=	--build=${MACHINE_GNU_PLATFORM:Q}
.  endif
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM:Q}
.endif

# PKGINFODIR is the subdirectory of ${PREFIX} into which the info
# files are installed unless the software was configured with an
# installation prefix other than ${PREFIX}.
#
CONFIGURE_HAS_INFODIR?=	yes
.if ${GNU_CONFIGURE_PREFIX} == ${PREFIX}
GNU_CONFIGURE_INFODIR?=	${GNU_CONFIGURE_PREFIX}/${PKGINFODIR}
.else
GNU_CONFIGURE_INFODIR?=	${GNU_CONFIGURE_PREFIX}/info
.endif
.if defined(INFO_FILES) && !empty(CONFIGURE_HAS_INFODIR:M[yY][eE][sS])
CONFIGURE_ARGS+=	--infodir=${GNU_CONFIGURE_INFODIR:Q}
.endif

# PKGMANDIR is the subdirectory of ${PREFIX} into which the man and
# catman pages are installed unless the software was configured with
# an installation prefix other than ${PREFIX}.
#
CONFIGURE_HAS_MANDIR?=	 yes
.if ${GNU_CONFIGURE_PREFIX} == ${PREFIX}
GNU_CONFIGURE_MANDIR?=	${GNU_CONFIGURE_PREFIX}/${PKGMANDIR}
.else
GNU_CONFIGURE_MANDIR?=	${GNU_CONFIGURE_PREFIX}/man
.endif
.if !empty(CONFIGURE_HAS_MANDIR:M[yY][eE][sS])
CONFIGURE_ARGS+=	--mandir=${GNU_CONFIGURE_MANDIR:Q}
.endif

######################################################################
### configure-scripts-override (PRIVATE)
######################################################################
### configure-scripts-override modifies the GNU configure scripts in
### ${WRKSRC} so that the generated config.status scripts never do
### anything on "--recheck".  This is important in pkgsrc because we
### only ever want to run the configure checks during the configure
### phase, and "recheck" is often run during the build and install
### phases.
###
do-configure-pre-hook: configure-scripts-override

_SCRIPT.configure-scripts-override=					\
	${AWK} '/ *-recheck *\| *--recheck.*\)/ {			\
			print;						\
			print "	: Avoid regenerating within pkgsrc";	\
			print "	exit 0";				\
			next;						\
		}							\
		{ print }' $$file > $$file.override;			\
	${CHMOD} +x $$file.override;					\
	${TOUCH} -r $$file $$file.override;				\
	${MV} -f $$file.override $$file

OVERRIDE_DIRDEPTH.configure?=	${OVERRIDE_DIRDEPTH}

.PHONY: configure-scripts-override
configure-scripts-override:
	@${STEP_MSG} "Modifying GNU configure scripts to avoid --recheck"
.if defined(CONFIGURE_SCRIPTS_OVERRIDE) && !empty(CONFIGURE_SCRIPTS_OVERRIDE)
	@echo HERE
	${RUN} \
	cd ${WRKSRC};							\
	for file in ${CONFIGURE_SCRIPTS_OVERRIDE}; do			\
		${TEST} -f "$$file" || continue;			\
		${_SCRIPT.${.TARGET}};					\
	done
.else
	${RUN} \
	cd ${WRKSRC};							\
	depth=0; pattern=${CONFIGURE_SCRIPT:T};				\
	while ${TEST} $$depth -le ${OVERRIDE_DIRDEPTH.configure}; do	\
		for file in $$pattern; do				\
			${TEST} -f "$$file" || continue;		\
			${_SCRIPT.${.TARGET}};				\
		done;							\
		depth=`${EXPR} $$depth + 1`; pattern="*/$$pattern";	\
	done
.endif

######################################################################
### configure-scripts-osdep (PRIVATE)
######################################################################
### configure-scripts-osdep modifies the GNU configure scripts in
### ${WRKSRC} to support operating systems without upstream support
### in for example libtool.
###
do-configure-pre-hook: configure-scripts-osdep

.if ${OPSYS} == "MirBSD"
# awk script by Benny Siegert <bsiegert@mirbsd.de>
_SCRIPT.configure-scripts-osdep=					\
	${AWK} 'BEGIN { found = 0 }					\
		/dynamic linker characteristics.../ { found = 1 }	\
		/^netbsd/ {						\
			if (found) {					\
				sub("netbsd","mirbsd*|netbsd");		\
				found = 0;				\
			}						\
		}							\
		{ print $$0 }' $$file >$$file.override;			\
	${CHMOD} +x $$file.override;					\
	${TOUCH} -r $$file $$file.override;				\
	${MV} -f $$file.override $$file
.endif

.PHONY: configure-scripts-osdep
configure-scripts-osdep:
.if defined(_SCRIPT.configure-scripts-osdep) && !empty(_SCRIPT.configure-scripts-osdep)
	@${STEP_MSG} "Modifying GNU configure scripts for OS dependent support"
	${RUN} cd ${WRKSRC};						\
	depth=0; pattern=${CONFIGURE_SCRIPT:T};				\
	while ${TEST} $$depth -le ${OVERRIDE_DIRDEPTH.configure}; do	\
		for file in $$pattern; do				\
			${TEST} -f "$$file" || continue;		\
			${_SCRIPT.${.TARGET}};				\
		done;							\
		depth=`${EXPR} $$depth + 1`; pattern="*/$$pattern";	\
	done
.endif

GNU_CONFIGURE_STRICT?=	warn
.if ${GNU_CONFIGURE_STRICT:tl} != no
CONFIGURE_ARGS+=	--enable-option-checking=yes
.endif

.if ${GNU_CONFIGURE_QUIET:Uno:tl} == yes
CONFIGURE_ARGS+=	--quiet
.endif

_SHOW_UNKNOWN_CONFIGURE_OPTIONS_CMD= \
	cd ${WRKSRC}; \
	configures=$$( \
		for dir in ${CONFIGURE_DIRS}; do \
			cd ${WRKSRC} && cd "$$dir" && cd ${CONFIGURE_SCRIPT:H} \
			&& ${FIND} "$$PWD" -name ${CONFIGURE_SCRIPT:T}; \
		done \
		| ${SED} -e 's,^${WRKSRC}/,./,' \
		| LC_ALL=C ${SORT} -u \
		| ${TR} '\n' ' ' \
		| ${SED} 's, $$,,'); \
	exitcode=0; \
	for opt in "" \
		${CONFIGURE_ARGS:M--enable-*} \
		${CONFIGURE_ARGS:M--disable-*} \
		${CONFIGURE_ARGS:M--with-*} \
		${CONFIGURE_ARGS:M--without-*}; do \
		[ "$$opt" ] || continue; \
		optvar=$${opt%%=*}; \
		optvar=$${optvar\#--}; \
		optvar=$$(${ECHO} "$$optvar" \
			| ${SED} -e 's/[-+.]/_/g' \
				-e 's,^disable_,enable_,' \
				-e 's,^without_,with_,'); \
		[ "$$optvar" = 'enable_option_checking' ] && continue; \
		${GREP} -e "^$$optvar$$" -e "{$$optvar+set}" $$configures 1>/dev/null || { \
			${ERROR_MSG} "[gnu-configure.mk] option $$opt not found in $$configures"; \
			exitcode=1; \
		}; \
	done

# Inspects the configure scripts of a package to see whether each option
# of the form --enable-* or --disable-* or --with-* or --without-* is
# known to at least one of the configure scripts.  If that is not the
# case, the option is outdated in most cases, or it has a typo.
#
# See also: GNU_CONFIGURE_STRICT configure-help
#
# Keywords: GNU_CONFIGURE_STRICT configure-help
show-unknown-configure-options: .PHONY
	${RUN} ${MAKE} patch
	${RUN} ${_SHOW_UNKNOWN_CONFIGURE_OPTIONS_CMD}

.if ${GNU_CONFIGURE_STRICT:tl} == yes
USE_TOOLS+=	find grep sed sort tr

pre-configure-checks-hook: _check-unknown-configure-options
_check-unknown-configure-options: .PHONY
	${RUN} ${_SHOW_UNKNOWN_CONFIGURE_OPTIONS_CMD}; exit $$exitcode
.endif
