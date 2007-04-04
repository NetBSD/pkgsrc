# $NetBSD: java-vm.mk,v 1.57 2007/04/04 14:32:52 tv Exp $
#
# This Makefile fragment handles Java dependencies and make variables,
# and is meant to be included by packages that require Java either at
# build-time or at run-time.
#
# User-settable variables:
#
# PKG_JVM_DEFAULT
#	The JVM that should be used if nothing particular is specified.
#
#	Possible values: jdk sun-jdk13 blackdown-jdk13 kaffe
#		sun-jdk14 jdk14 sun-jdk15 sun-jdk6 scsl-jdk15
#	Default value: (platform-dependent)
#
# Package-settable variables:
#
# USE_JAVA
#	When set to "yes", a build-time dependency on the JDK is added.
#	When set to "run", a run-time dependency on the JRE is added.
#
#	Possible values: yes run
#	Default value: yes
#
# USE_JAVA2
#	When the package needs a Java 2 implementation, this variable
#	should be set to "yes". It can also be set to "1.4", "1.5",
#	or "6" require an even more recent implementation.
#
#	Possible values: yes no 1.4 1.5 6
#	Default value: no
#
# PKG_JVMS_ACCEPTED
#	The list of JVMs that may be used as possible implementations.
#
# Variables set by this file:
#
# PKG_JVM
#	The name of the selected Java implementation.
#
# PKG_JAVA_HOME
#	The directory where the JVM is installed.
#

.if !defined(JAVA_VM_MK)
JAVA_VM_MK=	# defined

.include "../../mk/bsd.prefs.mk"

USE_JAVA?=	yes
USE_JAVA2?=	no

PKG_JVM_DEFAULT?=	# empty
PKG_JVMS_ACCEPTED?=	${_PKG_JVMS}

# This is a list of all of the JDKs that may be used.
#
_PKG_JVMS.6=		sun-jdk6
_PKG_JVMS.1.5=		${_PKG_JVMS.6} sun-jdk15 scsl-jdk15
_PKG_JVMS.1.4=		${_PKG_JVMS.1.5} sun-jdk14 jdk14
_PKG_JVMS.yes=		${_PKG_JVMS.1.4} sun-jdk13 blackdown-jdk13 kaffe
_PKG_JVMS.no=		${_PKG_JVMS.yes} jdk
_PKG_JVMS=		${_PKG_JVMS.${USE_JAVA2}}

# To be deprecated: if PKG_JVM is explicitly set, then use it as the
# default JVM.  Note that this has lower precedence than PKG_JVM_DEFAULT.
#
.if defined(PKG_JVM)
.  if !empty(PKG_JVM)
_PKG_JVM_DEFAULT:=	${PKG_JVM}
.  endif
.endif

# Set the default JVM for this platform.
#
.if !empty(PKG_JVM_DEFAULT)
_PKG_JVM_DEFAULT=	${PKG_JVM_DEFAULT}
.endif
.if !defined(_PKG_JVM_DEFAULT)
.  if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || \
      !empty(MACHINE_PLATFORM:MLinux-*-i[3456]86)
_PKG_JVM_DEFAULT?=	sun-jdk
.  elif !empty(MACHINE_PLATFORM:MNetBSD-*-powerpc)
_PKG_JVM_DEFAULT?=	blackdown-jdk13
.  elif !empty(MACHINE_PLATFORM:MDarwin-*-*)
_PKG_JVM_DEFAULT?=	sun-jdk
.  else
_PKG_JVM_DEFAULT?=	kaffe
.  endif
.endif

# These lists are copied from the JVM package Makefiles.
_ONLY_FOR_PLATFORMS.blackdown-jdk13= \
	DragonFly-*-i386 \
	Linux-*-i[3-6]86 Linux-*-powerpc Linux-*-sparc \
	NetBSD-*-i386 NetBSD-*-powerpc NetBSD-*-sparc
.if !empty(USE_JAVA:M[rR][uU][nN])
_ONLY_FOR_PLATFORMS.blackdown-jdk13+= \
	Linux-*-arm \
	NetBSD-*-arm
.endif
_ONLY_FOR_PLATFORMS.jdk= \
	DragonFly-*-i386 \
	Linux-*-i[3-6]86 \
	NetBSD-*-i386
_ONLY_FOR_PLATFORMS.jdk14= \
	DragonFly-*-i386 \
	NetBSD-[2-9].*-i386
_ONLY_FOR_PLATFORMS.kaffe= \
	*-*-alpha *-*-arm *-*-arm32 *-*-i386 *-*-m68k *-*-mips* *-*-sparc *-*-powerpc
_ONLY_FOR_PLATFORMS.scsl-jdk15= \
	NetBSD-[2-9].*-i386
_ONLY_FOR_PLATFORMS.sun-jdk13= \
	Darwin-*-* \
	DragonFly-*-i386 \
	FreeBSD-6.*-i386 \
	Linux-*-i[3-6]86 \
	NetBSD-*-i386
_ONLY_FOR_PLATFORMS.sun-jdk14= \
	Darwin-[678].*-* \
	DragonFly-*-i386 \
	FreeBSD-6.*-i386 \
	Linux-*-i[3-6]86 \
	NetBSD-*-i386
_ONLY_FOR_PLATFORMS.sun-jdk15= \
	Darwin-8.*-* \
	DragonFly-*-i386 \
	FreeBSD-6.*-i386 \
	Linux-*-i[3-6]86 \
	NetBSD-*-i386 NetBSD-*-x86_64
_ONLY_FOR_PLATFORMS.sun-jdk6= \
	DragonFly-*-i386 \
	FreeBSD-6.*-i386 \
	Linux-*-i[3-6]86 \
	NetBSD-*-i386

# Set the accepted JVMs for this platform.
.for _jvm_ in ${_PKG_JVMS}
.  for _pattern_ in ${_ONLY_FOR_PLATFORMS.${_jvm_}}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_PKG_JVMS_ACCEPTED+=	${PKG_JVMS_ACCEPTED:M${_jvm_}}
.    endif
.  endfor
.endfor

_JAVA_PKGBASE.blackdown-jdk13=	blackdown-jdk13
_JAVA_PKGBASE.jdk=		jdk
_JAVA_PKGBASE.jdk14=		jdk14
_JAVA_PKGBASE.kaffe=		kaffe
_JAVA_PKGBASE.scsl-jdk15=	scsl-jre15
_JAVA_PKGBASE.sun-jdk13=	sun-jre13
_JAVA_PKGBASE.sun-jdk14=	sun-jre14
_JAVA_PKGBASE.sun-jdk15=	sun-jre15
_JAVA_PKGBASE.sun-jdk6=		sun-jre6

# Mark the acceptable JVMs and check which JVM packages are installed.
.for _jvm_ in ${_PKG_JVMS_ACCEPTED}
_PKG_JVM_OK.${_jvm_}=	yes
_PKG_JVM_INSTALLED.${_jvm_}!= \
	if ${PKG_INFO} -qe ${_JAVA_PKGBASE.${_jvm_}}; then		\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.endfor

# Convert "sun-jdk" into "sun-jdk1[345]" depending on the
# platform.  Recent versions of NetBSD and Linux can use the 1.3-1.5
# versions of the Sun JDK, so default to the newer installed one.
#
.if ${_PKG_JVM_DEFAULT} == "sun-jdk"
.  if !empty(MACHINE_PLATFORM:MNetBSD-1.6[M-Z]*-i386) || \
      !empty(MACHINE_PLATFORM:MNetBSD-[2-9].*-i386) || \
      !empty(MACHINE_PLATFORM:MLinux-*-i[3456]86) || \
      !empty(MACHINE_PLATFORM:MDarwin-8.*-*)
.    if defined(_PKG_JVM_INSTALLED.scsl-jdk15) && \
	(${_PKG_JVM_INSTALLED.scsl-jdk15} == "yes")
_PKG_JVM_DEFAULT=	scsl-jdk15
.    elif defined(_PKG_JVM_INSTALLED.sun-jdk6) && \
	(${_PKG_JVM_INSTALLED.sun-jdk6} == "yes")
_PKG_JVM_DEFAULT=	sun-jdk6
.    elif defined(_PKG_JVM_INSTALLED.sun-jdk15) && \
	(${_PKG_JVM_INSTALLED.sun-jdk15} == "yes")
_PKG_JVM_DEFAULT=	sun-jdk15
.    elif defined(_PKG_JVM_INSTALLED.sun-jdk14) && \
	(${_PKG_JVM_INSTALLED.sun-jdk14} == "yes")
_PKG_JVM_DEFAULT=	sun-jdk14
.    elif defined(_PKG_JVM_INSTALLED.sun-jdk13) && \
	  (${_PKG_JVM_INSTALLED.sun-jdk13} == "yes")
_PKG_JVM_DEFAULT=	sun-jdk13
.    else
_PKG_JVM_DEFAULT=	sun-jdk15
.    endif
.  elif !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || \
	!empty(MACHINE_PLATFORM:MDarwin-*-*)
_PKG_JVM_DEFAULT=	sun-jdk13
.  endif
.endif

# Use one of the installed JVMs,...
#
.if !defined(_PKG_JVM)
.  for _jvm_ in ${_PKG_JVMS_ACCEPTED}
.    if !empty(_PKG_JVM_INSTALLED.${_jvm_}:M[yY][eE][sS])
_PKG_JVM?=	${_jvm_}
.    else
_PKG_JVM_FIRSTACCEPTED?= ${_jvm_}
.    endif
.  endfor
#
# ...otherwise, prefer the default one if it's accepted,...
#
.  if defined(_PKG_JVM_OK.${_PKG_JVM_DEFAULT}) && \
      !empty(_PKG_JVM_OK.${_PKG_JVM_DEFAULT}:M[yY][eE][sS])
_PKG_JVM=	${_PKG_JVM_DEFAULT}
.  endif
.endif
#
# ...otherwise, just use the first accepted JVM.
#
.if !defined(_PKG_JVM)
.  if defined(_PKG_JVM_FIRSTACCEPTED)
_PKG_JVM=	${_PKG_JVM_FIRSTACCEPTED}
.  endif
.endif
#
# If there are no acceptable JVMs, then generate an error.
#
.if !defined(_PKG_JVM)
# force an error
PKG_FAIL_REASON=	"no acceptable JVM found"
_PKG_JVM=		"none"
.endif

BUILDLINK_API_DEPENDS.blackdown-jdk13?=	blackdown-jdk13-[0-9]*
BUILDLINK_API_DEPENDS.blackdown-jre13?=	blackdown-jre13-[0-9]*
BUILDLINK_API_DEPENDS.jdk?=			jdk-[0-9]*
BUILDLINK_API_DEPENDS.jdk14?=		jdk14-[0-9]*
BUILDLINK_API_DEPENDS.kaffe?=		kaffe>=1.1.4
BUILDLINK_API_DEPENDS.scsl-jdk15?=		scsl-jdk15-[0-9]*
BUILDLINK_API_DEPENDS.scsl-jre15?=		scsl-jre15-[0-9]*
BUILDLINK_API_DEPENDS.sun-jdk13?=		sun-jdk13-[0-9]*
BUILDLINK_API_DEPENDS.sun-jre13?=		sun-jre13-[0-9]*
BUILDLINK_API_DEPENDS.sun-jdk14?=		sun-jdk14-[0-9]*
BUILDLINK_API_DEPENDS.sun-jre14?=		sun-jre14-[0-9]*
BUILDLINK_API_DEPENDS.sun-jdk15?=		sun-jdk15-[0-9]*
BUILDLINK_API_DEPENDS.sun-jre15?=		sun-jre15-[0-9]*
BUILDLINK_API_DEPENDS.sun-jdk6?=		sun-jdk6-[0-9]*
BUILDLINK_API_DEPENDS.sun-jre6?=		sun-jre6-[0-9]*

_JRE.blackdown-jdk13=	blackdown-jre13
_JRE.jdk=		jdk
_JRE.jdk14=		jdk14
_JRE.kaffe=		kaffe
_JRE.scsl-jdk15=	scsl-jre15
_JRE.sun-jdk13=		sun-jre13
_JRE.sun-jdk14=		sun-jre14
_JRE.sun-jdk15=		sun-jre15
_JRE.sun-jdk6=		sun-jre6

_JAVA_BASE_CLASSES=	classes.zip

.if ${_PKG_JVM} == "blackdown-jdk13"
_JDK_PKGSRCDIR=		../../lang/blackdown-jdk13
_JRE_PKGSRCDIR=		../../lang/blackdown-jre13
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/blackdown-1.3.1
. if !empty(MACHINE_PLATFORM:MNetBSD-*-powerpc)
MAKE_ENV+=		THREADS_FLAG="green"
CONFIGURE_ENV+=		THREADS_FLAG="green"
SCRIPTS_ENV+=		THREADS_FLAG="green"
. endif
.elif ${_PKG_JVM} == "jdk"
_JDK_PKGSRCDIR=		../../lang/jdk
_JRE_PKGSRCDIR=		${_JDK_PKGSRCDIR}
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/jdk-1.1.8
.elif ${_PKG_JVM} == "jdk14"
_JDK_PKGSRCDIR=		../../wip/jdk14
_JRE_PKGSRCDIR=		${_JDK_PKGSRCDIR}
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/jdk-1.4.2
.elif ${_PKG_JVM} == "kaffe"
_JDK_PKGSRCDIR=		../../lang/kaffe
_JRE_PKGSRCDIR=		${_JDK_PKGSRCDIR}
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/kaffe
.elif ${_PKG_JVM} == "scsl-jdk15"
_JDK_PKGSRCDIR=		../../lang/scsl-jdk15
_JRE_PKGSRCDIR=		../../lang/scsl-jre15
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/scsl-1.5
.elif ${_PKG_JVM} == "sun-jdk13"
_JDK_PKGSRCDIR=		../../lang/sun-jdk13
_JRE_PKGSRCDIR=		../../lang/sun-jre13
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/sun-1.3.1
.elif ${_PKG_JVM} == "sun-jdk14"
_JDK_PKGSRCDIR=		../../lang/sun-jdk14
_JRE_PKGSRCDIR=		../../lang/sun-jre14
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/sun-1.4
.elif ${_PKG_JVM} == "sun-jdk15"
_JDK_PKGSRCDIR=		../../lang/sun-jdk15
_JRE_PKGSRCDIR=		../../lang/sun-jre15
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/sun-1.5
UNLIMIT_RESOURCES+=	datasize
.elif ${_PKG_JVM} == "sun-jdk6"
_JDK_PKGSRCDIR=		../../lang/sun-jdk6
_JRE_PKGSRCDIR=		../../lang/sun-jre6
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/sun-6
UNLIMIT_RESOURCES+=	datasize
.endif

.if defined(_JAVA_HOME_DEFAULT)
_JAVA_HOME=		${_JAVA_HOME_DEFAULT}
.else
EVAL_PREFIX+=		_JAVA_HOME=${_JAVA_PKGBASE.${_PKG_JVM}}
.endif

# We always need a run-time dependency on the JRE.
.if defined(_JRE_PKGSRCDIR)
.  if exists(${_JRE_PKGSRCDIR}/buildlink3.mk)
.    include "${_JRE_PKGSRCDIR}/buildlink3.mk"
.  endif
.endif

# If we are building Java software, then we need a build-time dependency on
# the JDK.
#
.if empty(USE_JAVA:M[rR][uU][nN])
.  if defined(_JDK_PKGSRCDIR)
.    if exists(${_JDK_PKGSRCDIR}/buildlink3.mk)
.      include "${_JDK_PKGSRCDIR}/buildlink3.mk"
.    endif
.  endif
.endif

# PKG_JVM is a publicly readable variable containing the name of the JVM
#	we will be using.
#
# PKG_JAVA_HOME is a publicly readable variable containing ${JAVA_HOME}
#	for the PKG_JVM described above.
#
PKG_JVM:=		${_PKG_JVM}
.if defined(BUILDLINK_JAVA_PREFIX.${_PKG_JVM})
PKG_JAVA_HOME?=		${BUILDLINK_JAVA_PREFIX.${_PKG_JVM}}
.else
PKG_JAVA_HOME?=		${_JAVA_HOME}
.endif
.if !defined(CLASSPATH)
CLASSPATH_cmd=		${ECHO} `for p in					\
				${PKG_JAVA_HOME}/lib/${_JAVA_BASE_CLASSES}	\
				${PKG_JAVA_HOME}/lib/tools.jar; do		\
			${TEST} ! -f $$p || ${ECHO} $$p; done`			\
			. | ${TR} ' ' :
CLASSPATH?=		${CLASSPATH_cmd:sh}
.endif

ALL_ENV+=		CLASSPATH=${CLASSPATH:Q}
ALL_ENV+=		JAVA_HOME=${PKG_JAVA_HOME}
BUILD_DEFS+=		PKG_JVM_DEFAULT
BUILD_DEFS_EFFECTS+=	PKG_JVM PKG_JAVA_HOME
MAKEFLAGS+=		PKG_JVM=${PKG_JVM:Q}
PREPEND_PATH+=		${PKG_JAVA_HOME}/bin

.endif	# JAVA_VM_MK
