# $NetBSD: bsd.buildlink2.mk,v 1.1.2.2 2002/05/08 08:50:09 jlam Exp $
#
# This Makefile fragment is included by package buildlink2.mk files.  This
# file defines a macro target, _BUILDLINK_USE, that symlinks package files
# into a new hierarchy under ${BUILDLINK_DIR}.
#
# The variables required to be defined prior to including this file are
# listed below.  <pkgname> refers to the name of the package and should be
# used consistently throughout the buildlink2.mk file.
#
# BUILDLINK_PREFIX.<pkgname>	installation prefix of the package
#
# BUILDLINK_FILES.<pkgname>	files relative to ${BUILDLINK_PREFIX.<pkgname>}
#				to be symlinked into ${BUILDLINK_DIR};
#				libtool archive files are automatically
#				filtered out and not linked
#
# BUILDLINK_TARGETS		targets to be invoked during pre-configure;
#				the targets should be appended to this variable
#				using +=
#
# The variables that may optionally be defined:
#
# BUILDLINK_TRANSFORM.<pkgname>	sed arguments used to transform the name of
#				the source filename into a destination
#				filename
#
# The targets that may optionally be defined prior to including this file:
#
# <pkgname>-buildlink		this target should just invoke the
#				_BUILDLINK_USE macro target defined in this
#				file
#
# Example package buildlink2.mk file:
#
# .include "../../mk/bsd.buildlink2.mk"
#
# BUILDLINK_DEPENDS.foo?=	foo>=1.0
# DEPENDS+=			${BUILDLINK_DEPENDS.foo}:../../category/foo
#
# EVAL_PREFIX+=			BUILDLINK_PREFIX.foo=foo
# BUILDLINK_FILES.foo=		include/foo.h
# BUILDLINK_FILES.foo+=		include/bar.h
# BUILDLINK_FILES.foo+=		lib/libfoo.*
#
# # We need "libbar.*" to look like "libfoo.*".
# BUILDLINK_TRANSFORM+=		l:bar:foo
#
# BUILDLINK_TARGETS+=		foo-buildlink
#
# foo-buildlink: _BUILDLINK_USE

.if !defined(_BSD_BUILDLINK2_MK)
_BSD_BUILDLINK2_MK=	# defined

# _LIBTOOL_ARCHIVE_TRANSFORM creates $${dest} from $${file}, where
# $${file} is a libtool archive (*.la).  It allows libtool to properly
# interact with buildlink at link time by linking against the libraries
# pointed to by symlinks in ${BUILDLINK_DIR}.
#
_LIBTOOL_ARCHIVE_TRANSFORM_SED=						\
	-e "s|${LOCALBASE}\(/lib/[^ 	]*\.la\)|${BUILDLINK_DIR}\1|g"	\
	-e "s|${X11BASE}\(/lib/[^ 	]*\.la\)|${BUILDLINK_DIR}\1|g"

_LIBTOOL_ARCHIVE_TRANSFORM=						\
	${SED} ${_LIBTOOL_ARCHIVE_TRANSFORM_SED} $${file} > $${dest}

_BUILDLINK_USE: .USE
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.${.TARGET:S/-buildlink//}_buildlink_done; \
	if [ ! -f $${cookie} ]; then					\
		${ECHO_BUILDLINK_MSG} "Linking ${.TARGET:S/-buildlink//} files into ${BUILDLINK_DIR}."; \
		${MKDIR} ${BUILDLINK_DIR};				\
		case "${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}" in	\
		${X11BASE})						\
			${RM} -f ${BUILDLINK_X11PKG_DIR} 2>/dev/null;	\
			${LN} -sf ${BUILDLINK_DIR} ${BUILDLINK_X11PKG_DIR}; \
			buildlink_dir="${BUILDLINK_X11PKG_DIR}";	\
			;;						\
		*)							\
			buildlink_dir="${BUILDLINK_DIR}";		\
			;;						\
		esac;							\
		files="${BUILDLINK_FILES.${.TARGET:S/-buildlink//}:S/^/${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}\//g}"; \
		for file in $${files}; do				\
			rel_file=`${ECHO} $${file} | ${SED} -e "s|${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}/||"`; \
			if [ -z "${BUILDLINK_TRANSFORM.${.TARGET:S/-buildlink//}:Q}" ]; then \
				dest="$${buildlink_dir}/$${rel_file}";	\
			else						\
				dest=`${ECHO} $${buildlink_dir}/$${rel_file} | ${SED} ${BUILDLINK_TRANSFORM.${.TARGET:S/-buildlink//}}`; \
			fi;						\
			if [ -f $${file} ]; then			\
				dir=`${DIRNAME} $${dest}`;		\
				if [ ! -d $${dir} ]; then		\
					${MKDIR} $${dir};		\
				fi;					\
				${RM} -f $${dest};			\
				case $${file} in			\
				*.la)					\
					${_LIBTOOL_ARCHIVE_TRANSFORM};	\
					;;				\
				*)					\
					${LN} -sf $${file} $${dest};	\
					;;				\
				esac;					\
				if [ -z "${BUILDLINK_TRANSFORM.${.TARGET:S/-buildlink//}:Q}" ]; then \
					${ECHO} $${file} >> $${cookie};	\
				else					\
					${ECHO} "$${file} -> $${dest}" >> $${cookie}; \
				fi;					\
			else						\
				${ECHO} "$${file}: not found" >> $${cookie}; \
			fi;						\
		done;							\
		${TOUCH} ${TOUCH_FLAGS} $${cookie};			\
	fi

.endif	# _BSD_BUILDLINK2_MK
