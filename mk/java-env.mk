# $NetBSD: java-env.mk,v 1.12 2009/06/14 22:58:05 joerg Exp $
#
# This Makefile fragment handles Java wrappers and is meant to be included
# by packages that provide a Java build-time and/or run-time environment.
#
# The following variables can be defined in package Makefiles to tune the
# behavior of this file:
#
#	JAVA_CLASSPATH	Classpath that will be prepended on all invocations
#			to this implementation.  Optional.
#
#	JAVA_LD_LIBRARY_PATH
#			Value to prepend to LD_LIBRARY_PATH before running
#			the real command.  Optional; use *only* if necessary.
#
#	JAVA_HOME	Path to the directory holding the Java implementation.
#			Required.
#
#	JAVA_NAME	Base name of the Java implementation.  This will be
#			used as part of wrappers' names.  Required.
#
#	JAVA_UNLIMIT	List of resources to be unlimited at runtime.
#			Can include any of cmdsize, datasize and stacksize.
#			Optional.
#
#	JAVA_WRAPPERS	List of wrappers to be created under ${PREFIX}/bin,
#			pointing to binaries under ${JAVA_HOME}/bin.  The
#			names must match files in the later directory.
#			Required (if empty, the inclusion of this file is
#			useless).
#

.if !defined(JAVA_ENV_MK)
JAVA_ENV_MK=		# defined

JAVA_NAME?=		# undefined
JAVA_HOME?=		# undefined
JAVA_CLASSPATH?=	# empty
JAVA_LD_LIBRARY_PATH?=	# empty
JAVA_UNLIMIT?=		# empty
JAVA_WRAPPERS?=		# empty

.include "../../mk/bsd.prefs.mk"

.if !empty(JAVA_WRAPPERS)
INSTALLATION_DIRS+=	bin

ALTERNATIVES_SRC=	${WRKDIR}/.ALTERNATIVES
${WRKDIR}/.ALTERNATIVES:
.  for w in ${JAVA_WRAPPERS}
	@${ECHO} 'bin/${w} ${PREFIX}/bin/${JAVA_NAME}-${w}' \
		>>${WRKDIR}/.ALTERNATIVES
.  endfor

.  for w in ${JAVA_WRAPPERS}

JAVA_WRAPPER_BIN.${w}?=	${JAVA_HOME}/bin/${w}

post-build:		${WRKDIR}/${w}

.PHONY:			install-java-wrapper-${w}
post-install:		install-java-wrapper-${w}

.    if !target(${WRKDIR}/${w})
${WRKDIR}/${w}:
	@${ECHO} 'Generating ${w} wrapper...'
	@${ECHO} '#! ${SH}' >${WRKDIR}/${w}
	@${ECHO} 'PATH=${JAVA_HOME}/bin:$${PATH}; export PATH' >>${WRKDIR}/${w}
	@${ECHO} 'JAVA_HOME=${JAVA_HOME}; export JAVA_HOME' >>${WRKDIR}/${w}
	@${ECHO} 'JVM_HOME=${JAVA_HOME}; export JVM_HOME' >>${WRKDIR}/${w}
.      if !empty(JAVA_CLASSPATH)
	@${ECHO} 'CLASSPATH=${JAVA_CLASSPATH}:$${CLASSPATH}; export CLASSPATH' \
		>>${WRKDIR}/${w}
.      endif
.      if !empty(JAVA_LD_LIBRARY_PATH)
	@${ECHO} 'LD_LIBRARY_PATH=${JAVA_LD_LIBRARY_PATH}$${LD_LIBRARY_PATH:+:}$${LD_LIBRARY_PATH}; export LD_LIBRARY_PATH' \
		>>${WRKDIR}/${w}
.      endif
.      for f in ${JAVA_UNLIMIT}
	@${ECHO} '${ULIMIT_CMD_${f}}' >>${WRKDIR}/${w}
.      endfor
.      undef f
	@${ECHO} '${JAVA_WRAPPER_BIN.${w}} "$$@"' >>${WRKDIR}/${w}
.    endif

install-java-wrapper-${w}:
	${INSTALL_SCRIPT} ${WRKDIR}/${w} ${DESTDIR}${PREFIX}/bin/${JAVA_NAME}-${w}

.  endfor
.  undef w
.endif

# Handle the ${PREFIX}/java shared directory automatically.
REQD_DIRS+=		${PREFIX}/java

PLIST_SUBST+=		JAVA_HOME=${JAVA_HOME:Q}
FILES_SUBST+=		JAVA_HOME=${JAVA_HOME:Q}

.endif	# JAVA_ENV_MK
