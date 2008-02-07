# $NetBSD: gnu-configure.mk,v 1.7 2008/02/07 21:36:13 rillig Exp $

_VARGROUPS+=			gnu-configure
_USER_VARS.gnu-configure=	# none
_PKG_VARS.gnu-configure=	GNU_CONFIGURE GNU_CONFIGURE_PREFIX \
	GNU_CONFIGURE_INFODIR GNU_CONFIGURE_MANDIR \
	CONFIGURE_HAS_MANDIR CONFIGURE_HAS_INFODIR \
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

GNU_CONFIGURE_PREFIX?=	${PREFIX}
CONFIGURE_ARGS+=	--prefix=${GNU_CONFIGURE_PREFIX:Q}

USE_GNU_CONFIGURE_HOST?=	yes
.if !empty(USE_GNU_CONFIGURE_HOST:M[yY][eE][sS])
.  if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ARGS+=	--build=${NATIVE_MACHINE_GNU_PLATFORM:Q}
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
