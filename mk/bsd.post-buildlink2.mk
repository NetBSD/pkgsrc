# $NetBSD: bsd.post-buildlink2.mk,v 1.1.2.1 2002/05/08 08:35:26 jlam Exp $

ECHO_BUILDLINK_MSG?=	${ECHO_MSG} "=>"

# Add each of the *-buildlink targets as a prerequisite for the
# pre-configure target.  This ensures that the symlinks are created
# before any configure scripts are called.
#
.for _target_ in ${BUILDLINK_TARGETS}
pre-configure: ${_target_}
.endfor

.if defined(USE_BUILDLINK2_ONLY)
BUILDLINK_DIR=		${WRKDIR}/.buildlink
BUILDLINK_X11PKG_DIR=	${BUILDLINK_DIR:H}/.buildlink-x11pkg
CONFIGURE_ENV+=		BUILDLINK_DIR="${BUILDLINK_DIR}"
MAKE_ENV+=		BUILDLINK_DIR="${BUILDLINK_DIR}"
_BUILDLINK_CPPFLAGS=	-I${LOCALBASE}/include
_BUILDLINK_LDFLAGS=	-L${LOCALBASE}/lib

.if defined(USE_X11) || defined(USE_X11BASE) || defined(USE_IMAKE)
BUILD_DEPENDS+=		x11-links>=0.6:../../pkgtools/x11-links
BUILDLINK_X11_DIR=	${LOCALBASE}/share/x11-links
CONFIGURE_ENV+=		BUILDLINK_X11_DIR="${BUILDLINK_X11_DIR}"
MAKE_ENV+=		BUILDLINK_X11_DIR="${BUILDLINK_X11_DIR}"
_BUILDLINK_CPPFLAGS+=	-I${X11BASE}/include
_BUILDLINK_LDFLAGS+=	-L${X11BASE}/lib
.endif

CFLAGS:=		${_BUILDLINK_CPPFLAGS} ${CFLAGS}
CXXFLAGS:=		${_BUILDLINK_CPPFLAGS} ${CXXFLAGS}
CPPFLAGS:=		${_BUILDLINK_CPPFLAGS} ${CPPFLAGS}
LDFLAGS:=		${_BUILDLINK_LDFLAGS} ${LDFLAGS}

PATH:=			${BUILDLINK_DIR}/bin:${PATH}

pre-configure: buildlink-wrappers

_BUILDLINK_TRANSFORM+=	I:${LOCALBASE}:${BUILDLINK_DIR}
_BUILDLINK_TRANSFORM+=	L:${LOCALBASE}:${BUILDLINK_DIR}
_BUILDLINK_TRANSFORM+=	${BUILDLINK_TRANSFORM}
.if defined(USE_X11) || defined(USE_X11BASE) || defined(USE_IMAKE)
_BUILDLINK_TRANSFORM+=	II:${X11BASE}:${BUILDLINK_X11PKG_DIR},${BUILDLINK_X11_DIR}
_BUILDLINK_TRANSFORM+=	LL:${X11BASE}:${BUILDLINK_X11PKG_DIR},${BUILDLINK_X11_DIR}
.endif
_BUILDLINK_TRANSFORM+=	r:-I/usr/local
_BUILDLINK_TRANSFORM+=	r:-L/usr/local

# Change explicit paths "/usr/pkg/lib/libfoo.so" into "-L/usr/pkg/lib -lfoo".
#
_BUILDLINK_TRANSFORM_SED+= \
	-e "s|${LOCALBASE}/\([^	 ]*\)/lib\([^	 ]*\)\.a[^	 ]*|-L${LOCALBASE}/\1 -l\2|g" \
	-e "s|${LOCALBASE}/\([^	 ]*\)/lib\([^	 ]*\)\.so[^	 ]*|-L${LOCALBASE}/\1 -l\2|g" \
	-e "s|${X11BASE}/\([^	 ]*\)/lib\([^	 ]*\)\.a[^	 ]*|-L${X11BASE}/\1 -l\2|g" \
	-e "s|${X11BASE}/\([^	 ]*\)/lib\([^	 ]*\)\.so[^	 ]*|-L${X11BASE}/\1 -l\2|g"
#
# Transform "I:/usr/pkg:/buildlink" into:
#	-e "s|-I/usr/pkg |-I/buildlink |g"
#	-e "s|-I/usr/pkg$|-I/buildlink|g"
#	-e "s|-I/usr/pkg/\([^	 ]*\)|-I/buildlink/\1|g"
#
.for _transform_ in ${_BUILDLINK_TRANSFORM:MI\:*\:*}
_BUILDLINK_TRANSFORM_SED+= \
	-e "s|-I${_transform_:C/^I\:([^\:]*)\:([^\:]*)$/\1/} |-I${_transform_:C/^I\:([^\:]*)\:([^\:]*)$/\2/} |g" \
	-e "s|-I${_transform_:C/^I\:([^\:]*)\:([^\:]*)$/\1/}$$|-I${_transform_:C/^I\:([^\:]*)\:([^\:]*)$/\2/}|g" \
	-e "s|-I${_transform_:C/^I\:([^\:]*)\:([^\:]*)$/\1/}/\([^	 ]*\)|-I${_transform_:C/^I\:([^\:]*)\:([^\:]*)$/\2/}/\1|g"
.endfor
#
# Transform "II:/usr/X11R6:/buildlink,/x11-links" into:
#	-e "s|-I/usr/X11R6 |-I/buildlink -I/x11-links |g"
#	-e "s|-I/usr/X11R6$|-I/buildlink -I/x11-links|g"
#	-e "s|-I/usr/X11R6/\([^	 ]*\)|-I/buildlink/\1 -I/x11-links/\1|g"
#
.for _transform_ in ${_BUILDLINK_TRANSFORM:MII\:*\:*,*}
_BUILDLINK_TRANSFORM_SED+= \
	-e "s|-I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/} |-I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/} -I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/} |g" \
	-e "s|-I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}$$|-I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/} -I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/}|g" \
	-e "s|-I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}/\([^	 ]*\)|-I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/}/\1 -I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/}/\1|g"
.endfor
#
# Transform "L:/usr/pkg:/buildlink" into:
#	-e "s|-L/usr/pkg |-L/buildlink |g"
#	-e "s|-L/usr/pkg$|-L/buildlink|g"
#	-e "s|-L/usr/pkg/\([^	 ]*\)|-L/buildlink/\1|g"
#
.for _transform_ in ${_BUILDLINK_TRANSFORM:ML\:*\:*}
_BUILDLINK_TRANSFORM_SED+= \
	-e "s|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\1/} |-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\2/} |g" \
	-e "s|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\1/}$$|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\2/}|g" \
	-e "s|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\1/}/\([^	 ]*\)|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\2/}/\1|g"
_BUILDLINK_UNTRANSFORM_SED+= \
	-e "s|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\2/} |-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\1/} |g" \
	-e "s|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\2/}$$|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\1/}|g" \
	-e "s|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\2/}/\([^	 ]*\)|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\1/}/\1|g"
.endfor
#
# Transform "LL:/usr/X11R6:/buildlink,/x11-links" into:
#	-e "s|-L/usr/X11R6 |-L/buildlink -L/x11-links |g"
#	-e "s|-L/usr/X11R6$|-L/buildlink -L/x11-links|g"
#	-e "s|-L/usr/X11R6/\([^	 ]*\)|-L/buildlink/\1 -L/x11-links/\1|g"
#
.for _transform_ in ${_BUILDLINK_TRANSFORM:MLL\:*\:*,*}
_BUILDLINK_TRANSFORM_SED+= \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/} |-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/} -L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/} |g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}$$|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/} -L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/}|g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}/\([^	 ]*\)|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/}/\1 -L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/}/\1|g"
_BUILDLINK_UNTRANSFORM_SED+= \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/} |-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/} |g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/} |-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/} |g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/}$$|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}|g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/}$$|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}|g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/}/\([^	 ]*\)|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}/\1|g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/}/\([^	 ]*\)|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}/\1|g"
.endfor
#
# Transform "l:foo:bar" into:
#	-e "s|-lfoo |-lbar |g"
#	-e "s|-lfoo$|-lbar|g"
#
.for _transform_ in ${_BUILDLINK_TRANSFORM:Ml\:*}
_BUILDLINK_TRANSFORM_SED+= \
	-e "s|-l${_transform_:C/^l\:([^\:]*)\:([^\:]*)$/\1/} |-l${_transform_:C/^l\:([^\:]*)\:([^\:]*)$/\2/} |g" \
	-e "s|-l${_transform_:C/^l\:([^\:]*)\:([^\:]*)$/\1/}$$|-l${_transform_:C/^l\:([^\:]*)\:([^\:]*)$/\2/}|g"
.endfor
#
# Fix up references to the x11-links directory.
#
.if defined(USE_X11) || defined(USE_X11BASE) || defined(USE_IMAKE)
_BUILDLINK_TRANSFORM_SED+= \
	-e "s|${BUILDLINK_DIR}/\(${BUILDLINK_X11_DIR:S/^${LOCALBASE}\///}\)|${LOCALBASE}/\1|g"
.endif
#
# Transform "r:-I/usr/local" into:
#	-e "s|-I/usr/local ||g"
#	-e "s|-I/usr/local$||g"
#	-e "s|-I/usr/local/\([^	 ]*\)||g"
#
.for _transform_ in ${_BUILDLINK_TRANSFORM:Mr\:*}
_BUILDLINK_TRANSFORM_SED+=						\
	-e "s|${_transform_:S/^r://} ||g"				\
	-e "s|${_transform_:S/^r://}$$||g"				\
	-e "s|${_transform_:S/^r://}/[^	 ]*||g"
.endfor

# Generate wrapper scripts for the compiler tools that sanitize the
# argument list by converting references to ${LOCALBASE} and ${X11BASE}
# into references to ${BUILDLINK_DIR}, ${BUILDLINK_X11PKG_DIR}, and
# ${BUILDLINK_X11_DIR}.  These wrapper scripts are to be used instead of
# the actual compiler tools when building software.
#
# BUILDLINK_CC, BUILDLINK_LD, etc. are the full paths to the wrapper
# scripts.
#
# The scripts are tweakable with the following variables:
#
# _BUILDLINK_TRANSFORM_ARGS_SH.<wrappee>
#	A bit of shell code that echoes to stdout a command to transform
#	"$*" into "$args", where "$args" is used as the argument list for
#	the actual invocation of the command.  The default transformation
#	alters references to ${LOCALBASE} and ${X11BASE} into
#	${BUILDLINK_*DIR} by running "$*" through sed invoked with
#	${_BUILDLINK_TRANSFORM_SED}.
#
# _BUILDLINK_SANITIZE_PATH_SH.<wrappee>
#	A bit of shell code that echoes to stdout a command to remove
#	${BUILDLINK_DIR}/bin from the PATH.
#
# _BUILDLINK_WRAPPER_LOG_SH.<wrappee>
#	A bit of shell code that echoes to stdout a command to log the
#	command to-be-executed.
# 
_BUILDLINK_WRAPPEES=		AS CC CXX CPP LD
.if defined(USE_FORTRAN)
_BUILDLINK_WRAPPEES+=		FC F77
.endif
.if defined(USE_LIBTOOL)
PKGLIBTOOL=			${BUILDLINK_LIBTOOL}
_BUILDLINK_WRAPPEES+=		LIBTOOL
.endif
.if defined(USE_X11) || defined(USE_X11BASE) || defined(USE_IMAKE)
IMAKE?=				${X11BASE}/bin/imake
_BUILDLINK_WRAPPEES+=		IMAKE
.endif
_ALIASES.AS=	as
_ALIASES.CC=	cc gcc
_ALIASES.CXX=	c++ g++
_ALIASES.CPP=	cpp
_ALIASES.FC=	f77 g77
_ALIASES.LD=	ld

.for _wrappee_ in ${_BUILDLINK_WRAPPEES}
_BUILDLINK_WRAPPERS_ENV.${_wrappee_}= \
	${_wrappee_}="${BUILDLINK_${_wrappee_}:T}"
_BUILDLINK_TRANSFORM_ARGS_SH.${_wrappee_} = \
	${_BUILDLINK_TRANSFORM_ARGS_SH}
_BUILDLINK_SANITIZE_PATH_SH.${_wrappee_}= \
	${_BUILDLINK_SANITIZE_PATH_SH}
_BUILDLINK_WRAPPER_LOG_SH.${_wrappee_}= \
	${ECHO} "${ECHO} $${absdir}"${${_wrappee_}:Q}' $$args >> ${BUILDLINK_DIR}/.wrapper.log';
.endfor

_BUILDLINK_TRANSFORM_ARGS_SH= \
	${ECHO} 'args=`${ECHO} $$* | ${SED} ${_BUILDLINK_TRANSFORM_SED}`';
_BUILDLINK_SANITIZE_PATH_SH= \
	${ECHO} 'PATH="${PATH:C/:${BUILDLINK_DIR}[^:]*//:C/${BUILDLINK_DIR}[^:]*://}"';

# Don't bother adding AS, CPP to the configure or make environments --
# otherwise, it seems to break some configure scripts.
#
_BUILDLINK_WRAPPERS_ENV.AS=		# empty
_BUILDLINK_WRAPPERS_ENV.CPP=		# empty

# Don't override the default LIBTOOL setting in the environment, as
# it's already correct, and don't sanitize the PATH because we want
# libtool to invoke the wrapper scripts, too.
#
.if defined(USE_LIBTOOL)
_BUILDLINK_WRAPPERS_ENV.LIBTOOL=	# empty
_BUILDLINK_SANITIZE_PATH_SH.LIBTOOL=	# empty
.endif

# Don't transform the arguments for imake, which uses the C preprocessor
# to generate Makefiles, so that imake will find its config files.
#
.if defined(USE_X11) || defined(USE_X11BASE) || defined(USE_IMAKE)
_BUILDLINK_TRANSFORM_ARGS_SH.IMAKE=	${ECHO} 'args="$$*"';
.endif

.for _wrappee_ in ${_BUILDLINK_WRAPPEES}
CONFIGURE_ENV+=	${_BUILDLINK_WRAPPERS_ENV.${_wrappee_}}
MAKE_ENV+=	${_BUILDLINK_WRAPPERS_ENV.${_wrappee_}}

BUILDLINK_${_wrappee_}=	\
	${BUILDLINK_DIR}/bin/${${_wrappee_}:T:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}

buildlink-wrappers: ${BUILDLINK_${_wrappee_}}
${BUILDLINK_${_wrappee_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_BUILDLINK_MSG}		\
		"Creating wrapper: ${.TARGET}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	wrappee="${${_wrappee_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}";	\
	case $${wrappee} in						\
	/*)	absdir=;						\
		;;							\
	*)	OLDIFS="$$IFS";						\
		IFS=":";						\
		for dir in $${PATH}; do					\
			case $${dir} in					\
			*${BUILDLINK_DIR}*)				\
				;;					\
			*)	if [ -x $${dir}/$${wrappee} ]; then	\
					absdir=$${dir}/;		\
					wrappee=$${absdir}$${wrappee};	\
					break;				\
				fi;					\
				;;					\
			esac;						\
		done;							\
		IFS="$$OLDIFS";						\
		if [ ! -x "$${wrappee}" ]; then				\
			${ECHO_MSG} "$${wrappee}: No such file";	\
			exit 1;						\
		fi;							\
		;;							\
	esac;								\
	${MKDIR} -p ${BUILDLINK_DIR}/bin;				\
	( ${ECHO} '#!/bin/sh';						\
	  ${_BUILDLINK_TRANSFORM_ARGS_SH.${_wrappee_}}			\
	  ${_BUILDLINK_SANITIZE_PATH_SH.${_wrappee_}}			\
	  ${_BUILDLINK_WRAPPER_LOG_SH.${_wrappee_}}			\
	  ${ECHO} "exec $${absdir}"${${_wrappee_}:Q}' $$args';		\
	) > ${.TARGET};							\
	${CHMOD} +x ${.TARGET}

.  for _alias_ in ${_ALIASES.${_wrappee_}:S/^/${BUILDLINK_DIR}\/bin\//}
.    if !target(${_alias_})
buildlink-wrappers: ${_alias_}
${_alias_}: ${BUILDLINK_${_wrappee_}}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_BUILDLINK_MSG}		\
		"Linking wrapper: ${.TARGET}"
	${_PKG_SILENT}${_PKG_DEBUG}${LN} ${BUILDLINK_${_wrappee_}} ${.TARGET}
.    endif
.  endfor # _alias_
.endfor   # _wrappee_

# Libtool archives (*.la) are altered to change recorded paths to not refer
# to ${BUILDLINK_DIR}.  Redundant -Ldir options are also collapsed or
# removed to clean up the resulting libtool archives.
#
.if defined(USE_LIBTOOL)
post-build: buildlink-libtool-fix
buildlink-libtool-fix: ${BUILDLINK_DIR}/.buildlink_libtool_fix_done

_LIBTOOL_ARCHIVE_PATTERNS=	*.lai
_LIBTOOL_ARCHIVE_PATTERNS_FIND= \
	\( ${_LIBTOOL_ARCHIVE_PATTERNS:S/$/!/:S/^/-o -name !/:S/!/"/g:S/-o//1} \)
_LIBTOOL_ARCHIVES= \
	`cd ${WRKSRC}; ${FIND} . ${_LIBTOOL_ARCHIVE_PATTERNS_FIND} -print | ${SED} -e 's|^\./||' | ${SORT}`

_LIBTOOL_ARCHIVE_UNTRANSFORM_SED=	${LIBTOOL_ARCHIVE_UNTRANSFORM_SED}
_LIBTOOL_ARCHIVE_UNTRANSFORM_SED+=	${_BUILDLINK_UNTRANSFORM_SED}
_LIBTOOL_ARCHIVE_UNTRANSFORM_SED+=	-e "s|-L/usr/lib ||g"
_LIBTOOL_ARCHIVE_UNTRANSFORM_SED+=	-e "s|-L/usr/lib$$||g"

${BUILDLINK_DIR}/.buildlink_libtool_fix_done:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${BUILDLINK_DIR}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_BUILDLINK_MSG}		\
		"Fixing libtool archives."
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC};			\
	for file in ${_LIBTOOL_ARCHIVES}; do				\
		${SED}	${_LIBTOOL_ARCHIVE_UNTRANSFORM_SED}		\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
		deps=`							\
			. $${file};					\
			L=;						\
			l=;						\
			lexist=;					\
			for i in $${dependency_libs};	do		\
				case "$$i" in				\
				-L*)	case "$$L" in			\
					*"$$i "*) ;;			\
					*"$$i") ;;			\
					*) L="$$L $$i" ;;		\
					esac ;;				\
				-l*)	lexist=1;			\
					l="$$l $$i" ;;			\
				*)	l="$$l $$i" ;;			\
				esac;					\
			done;						\
			if [ -z "$$lexist" ]; then			\
				L=;					\
			fi;						\
			${ECHO} $$L$$l;					\
		`;							\
		${SED}	-e "s|^\(dependency_libs\)=.*|\1=\'$$deps\'|g"	\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
		${ECHO} $${file} >> ${.TARGET};				\
	done
.endif

.endif	# USE_BUILDLINK2_ONLY
