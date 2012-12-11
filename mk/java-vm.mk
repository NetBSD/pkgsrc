# $NetBSD: java-vm.mk,v 1.90 2012/12/11 14:54:00 ryoon Exp $
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
#	Possible values: kaffe openjdk7 openjdk7-bin
#		sun-jdk6 sun-jdk7 jdk15 jdk16
#	Default value: (platform-dependent)
#
# Package-settable variables:
#
# USE_JAVA
#	When set to "yes", a build-time dependency on the JDK and
#	                   a run-time dependency on the JRE are added.
#	When set to "run", a run-time dependency on the JRE is added.
#	When set to "build", a build-time dependency on the JRE is added.
#
#	Possible values: yes run build
#	Default value: yes
#
# USE_JAVA2
#	When the package needs a Java 2 implementation, this variable
#	should be set to "yes". It can also be set to "1.4", "1.5", "6"
#	or "7" require an even more recent implementation.
#
#	Possible values: yes no 1.4 1.5 6 7
#	Default value: no
#
# PKG_JVMS_ACCEPTED
#	The list of JVMs that may be used as possible implementations.
#
# Variables set by this file:
#
# JAVA_BINPREFIX
#	The prefix for the Java binaries. The path to the real binaries
#	is constructed by appending -${program} to it.
#
#	Examples:
#	* ${JAVA_BINPREFIX}-java is the path to the Java interpreter.
#	* ${JAVA_BINPREFIX}-javac is the path to the Java compiler.
#
# PKG_JVM
#	The name of the selected Java implementation.
#
# PKG_JAVA_HOME
#	The directory where the JVM is installed.
#

.if !defined(JAVA_VM_MK)
JAVA_VM_MK=	# defined

_VARGROUPS+=		java
_USER_VARS.java=	PKG_JVM_DEFAULT
_PKG_VARS.java=		USE_JAVA USE_JAVA2 PKG_JVMS_ACCEPTED
_SYS_VARS.java=		PKG_JVM PKG_JAVA_HOME JAVA_BINPREFIX

.include "../../mk/bsd.prefs.mk"

USE_JAVA?=	yes
USE_JAVA2?=	no

PKG_JVM_DEFAULT?=	# empty
PKG_JVMS_ACCEPTED?=	${_PKG_JVMS}

# This is a list of all of the JDKs that may be used.
#
_PKG_JVMS.7=		openjdk7 openjdk7-bin sun-jdk7
_PKG_JVMS.6=		${_PKG_JVMS.7} sun-jdk6 jdk16
_PKG_JVMS.1.5=		${_PKG_JVMS.6} jdk15
_PKG_JVMS.1.4=		${_PKG_JVMS.1.5}
_PKG_JVMS.yes=		${_PKG_JVMS.1.4} kaffe
_PKG_JVMS.no=		${_PKG_JVMS.yes}
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
.  if !empty(MACHINE_PLATFORM:MNetBSD-[456789].*-i386) || \
      !empty(MACHINE_PLATFORM:MNetBSD-[56789].*-x86_64)
_PKG_JVM_DEFAULT?=	openjdk7
.  elif !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || \
      !empty(MACHINE_PLATFORM:MLinux-*-i[3456]86) || \
      !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
_PKG_JVM_DEFAULT?=	sun-jdk6
.  elif !empty(MACHINE_PLATFORM:MDarwin-*-*)
_PKG_JVM_DEFAULT?=	sun-jdk6
.  elif !empty(MACHINE_PLATFORM:MSunOS-5.11-i386) || \
        !empty(MACHINE_PLATFORM:MSunOS-5.11-x86_64)
_PKG_JVM_DEFAULT?=	sun-jdk6
.  elif !empty(MACHINE_PLATFORM:MDragonFly-*-*)
_PKG_JVM_DEFAULT?=	openjdk7
.  else
_PKG_JVM_DEFAULT?=	kaffe
.  endif
.endif

# These lists are copied from the JVM package Makefiles.
_ONLY_FOR_PLATFORMS.jdk15= \
	DragonFly-*-* \
	FreeBSD-8.[1-9]*-i386 FreeBSD-8.[1-9]*-x86_64 \
	NetBSD-[2-9].*-i386 NetBSD-[4-9].*-x86_64
_ONLY_FOR_PLATFORMS.jdk16= \
	DragonFly-*-* \
	NetBSD-[2-9].*-i386 NetBSD-[4-9].*-x86_64
_ONLY_FOR_PLATFORMS.kaffe= \
	*-*-alpha *-*-arm *-*-arm32 *-*-i386 *-*-m68k \
	*-*-mipsel* *-*-sparc *-*-powerpc 
# exclude *-*-x86_64 from kaffe list as it apparently doesn't work
_ONLY_FOR_PLATFORMS.sun-jdk6= \
	Darwin-9.*-i386 Darwin-9.*-x86_64 \
	Darwin-10.*-i386 Darwin-10.*-x86_64 \
	Darwin-11.*-i386 Darwin-11.*-x86_64 \
	DragonFly-*-i386 \
	FreeBSD-6.*-i386 \
	Linux-*-i[3-6]86 \
	Linux-*-x86_64 \
	NetBSD-*-i386 NetBSD-*-x86_64 \
	SunOS-5.11-i386 \
	SunOS-5.11-x86_64
_ONLY_FOR_PLATFORMS.openjdk7= \
	DragonFly-*-* \
	NetBSD-[4-9]*-i386 \
	NetBSD-[5-9]*-x86_64
_ONLY_FOR_PLATFORMS.openjdk7-bin= \
	NetBSD-[5-9]*-i386 \
	NetBSD-[5-9]*-x86_64
_ONLY_FOR_PLATFORMS.sun-jdk7= \
	Darwin-9.*-i386 Darwin-9.*-x86_64 \
	Darwin-10.*-i386 Darwin-10.*-x86_64 \
	Darwin-11.*-i386 Darwin-11.*-x86_64 \
	DragonFly-*-i386 \
	FreeBSD-6.*-i386 \
	Linux-*-i[3-6]86 \
	Linux-*-x86_64 \
	NetBSD-[6-9]*-i386 NetBSD-[6-9]*-x86_64 \
	SunOS-5.11-i386 \
	SunOS-5.11-x86_64

# Set ONLY_FOR_PLATFORM based on accepted JVMs
.for _jvm_ in ${PKG_JVMS_ACCEPTED}
ONLY_FOR_PLATFORM+=	${_ONLY_FOR_PLATFORMS.${_jvm_}}
.endfor

# Set the accepted JVMs for this platform.
.for _jvm_ in ${_PKG_JVMS}
.  for _pattern_ in ${_ONLY_FOR_PLATFORMS.${_jvm_}}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_PKG_JVMS_ACCEPTED+=	${PKG_JVMS_ACCEPTED:M${_jvm_}}
.    endif
.  endfor
.endfor

_JAVA_PKGBASE.jdk=		jdk
_JAVA_PKGBASE.jdk14=		jdk14
_JAVA_PKGBASE.jdk15=		jdk15
_JAVA_PKGBASE.jdk16=		jdk16
_JAVA_PKGBASE.kaffe=		kaffe
_JAVA_PKGBASE.openjdk7=		openjdk7
_JAVA_PKGBASE.openjdk7-bin=	openjdk7-bin
_JAVA_PKGBASE.sun-jdk6=		sun-jre6
_JAVA_PKGBASE.sun-jdk7=		sun-jre7

# The following is copied from the respective JVM Makefiles.
_JAVA_NAME.jdk=			jdk11
_JAVA_NAME.jdk14=		jdk14
_JAVA_NAME.kaffe=		kaffe
_JAVA_NAME.openjdk7=		openjdk7
_JAVA_NAME.openjdk7-bin=	openjdk7-bin
_JAVA_NAME.sun-jdk6=		sun6
_JAVA_NAME.sun-jdk7=		sun7

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

BUILDLINK_API_DEPENDS.jdk15?=		jdk15-[0-9]*
BUILDLINK_API_DEPENDS.jdk16?=		jdk16-[0-9]*
BUILDLINK_API_DEPENDS.kaffe?=		kaffe>=1.1.4
BUILDLINK_API_DEPENDS.openjdk7?=	openjdk7-[0-9]*
BUILDLINK_API_DEPENDS.openjdk7-bin?=	openjdk7-bin-[0-9]*
BUILDLINK_API_DEPENDS.sun-jdk6?=	sun-jdk6-[0-9]*
BUILDLINK_API_DEPENDS.sun-jre6?=	sun-jre6-[0-9]*
BUILDLINK_API_DEPENDS.sun-jdk7?=	sun-jdk7-[0-9]*
BUILDLINK_API_DEPENDS.sun-jre7?=	sun-jre7-[0-9]*

_JRE.jdk15=		jdk15
_JRE.jdk16=		jdk16
_JRE.kaffe=		kaffe
_JRE.openjdk7=		openjdk7
_JRE.openjdk7-bin=	openjdk7-bin
_JRE.sun-jdk6=		sun-jre6
_JRE.sun-jdk7=		sun-jre7

_JAVA_BASE_CLASSES=	classes.zip

.if ${_PKG_JVM} == "jdk15"
_JDK_PKGSRCDIR=		../../wip/jdk15
_JRE_PKGSRCDIR=		${_JDK_PKGSRCDIR}
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/jdk-1.5.0
.elif ${_PKG_JVM} == "jdk16"
_JDK_PKGSRCDIR=		../../wip/jdk16
_JRE_PKGSRCDIR=		${_JDK_PKGSRCDIR}
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/jdk-1.6.0
.elif ${_PKG_JVM} == "kaffe"
_JDK_PKGSRCDIR=		../../lang/kaffe
_JRE_PKGSRCDIR=		${_JDK_PKGSRCDIR}
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/kaffe
.elif ${_PKG_JVM} == "openjdk7"
_JDK_PKGSRCDIR=		../../lang/openjdk7
_JRE_PKGSRCDIR=		${_JDK_PKGSRCDIR}
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/openjdk7
.elif ${_PKG_JVM} == "openjdk7-bin"
_JDK_PKGSRCDIR=		../../lang/openjdk7-bin
_JRE_PKGSRCDIR=		${_JDK_PKGSRCDIR}
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/openjdk7-bin
.elif ${_PKG_JVM} == "sun-jdk6"
_JDK_PKGSRCDIR=		../../lang/sun-jdk6
_JRE_PKGSRCDIR=		../../lang/sun-jre6
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/sun-6
UNLIMIT_RESOURCES+=	datasize
.elif ${_PKG_JVM} == "sun-jdk7"
_JDK_PKGSRCDIR=		../../lang/sun-jdk7
_JRE_PKGSRCDIR=		../../lang/sun-jre7
_JAVA_HOME_DEFAULT=	${LOCALBASE}/java/sun-7
UNLIMIT_RESOURCES+=	datasize
.endif

.if defined(_JAVA_HOME_DEFAULT)
_JAVA_HOME=		${_JAVA_HOME_DEFAULT}
.else
EVAL_PREFIX+=		_JAVA_HOME=${_JAVA_PKGBASE.${_PKG_JVM}}
.endif

# If we are not using Java for building, then we need a run-time dependency on
# the JRE, otherwise, build-time dependency on the JRE.
.if defined(_JRE_PKGSRCDIR)
.  if exists(${_JRE_PKGSRCDIR}/buildlink3.mk)
.    if !empty(USE_JAVA:M[bB][uU][iI][lL][dD])
BUILDLINK_DEPMETHOD.${_JRE.${_PKG_JVM}}=	build
.    endif
.    include "${_JRE_PKGSRCDIR}/buildlink3.mk"
.  endif
.endif

# If we are building Java software, then we need a build-time dependency on
# the JDK.
#
.if !empty(USE_JAVA:M[yE][eE][sS])
.  if defined(_JDK_PKGSRCDIR)
.    if exists(${_JDK_PKGSRCDIR}/buildlink3.mk)
.      include "${_JDK_PKGSRCDIR}/buildlink3.mk"
.    endif
.  endif
.endif

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
BUILD_DEFS+=		${_USER_VARS.java}
BUILD_DEFS_EFFECTS+=	${_SYS_VARS.java}
MAKEFLAGS+=		PKG_JVM=${PKG_JVM:Q}
PREPEND_PATH+=		${PKG_JAVA_HOME}/bin
JAVA_BINPREFIX=		${LOCALBASE}/bin/${_JAVA_NAME.${_PKG_JVM}}

PLIST_SUBST+=		PKG_JAVA_HOME=${PKG_JAVA_HOME:Q}
FILES_SUBST+=		PKG_JAVA_HOME=${PKG_JAVA_HOME:Q}

.endif	# JAVA_VM_MK
