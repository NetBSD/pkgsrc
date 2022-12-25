# $NetBSD: java-vm.mk,v 1.134 2022/12/25 19:18:05 abs Exp $
#
# This Makefile fragment provides a Java VM, either at build-time or at
# run-time, depending on the package's needs.
#
# User-settable variables:
#
# PKG_JVM_DEFAULT
#	The JVM that should be used if nothing particular is specified.
#
#	Possible values: kaffe openjdk8
#		sun-jdk7 oracle-jdk8
#		adoptopenjdk11-bin
#		openjdk-bin openjdk11
#		openjdk17 oracle-jdk17
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
#	should be set to "yes". It can also be set to "1.4", "1.5", "6".
#	"7", "8", "9" and "17" require an even more recent implementation.
#
#	Possible values: yes no 1.4 1.5 6 7 8 9 17
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
#	See PKG_JVMS_ACCEPTED for the possible values.
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
_SORTED_VARS.java=	PKG_JVMS_ACCEPTED

.include "../../mk/bsd.prefs.mk"

USE_JAVA?=	yes
USE_JAVA2?=	no

PKG_JVM_DEFAULT?=	# empty
PKG_JVMS_ACCEPTED?=	${_PKG_JVMS}

# This is a list of all of the JDKs that may be used.
#
# adoptopenjdk11-bin and openjdk-bin do not provide native NetBSD binaries
_PKG_JVMS.17=		openjdk17 oracle-jdk17
.if ${OPSYS} == "NetBSD"
_PKG_JVMS.9=		${_PKG_JVMS.17} openjdk11 adoptopenjdk11-bin openjdk-bin
.else
_PKG_JVMS.9=		${_PKG_JVMS.17} adoptopenjdk11-bin openjdk-bin openjdk11
.endif
_PKG_JVMS.8=		${_PKG_JVMS.9} openjdk8 oracle-jdk8
_PKG_JVMS.7=		${_PKG_JVMS.8} sun-jdk7
_PKG_JVMS.6=		${_PKG_JVMS.7} jdk16
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
.  if	!empty(MACHINE_PLATFORM:MNetBSD-7.*-i386) || \
	!empty(MACHINE_PLATFORM:MNetBSD-7.*-x86_64) || \
	!empty(MACHINE_PLATFORM:MNetBSD-*-sparc64) || \
	((!empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) || \
	  !empty(MACHINE_PLATFORM:MNetBSD-*-earmv[67]hf)) && \
	  ${OPSYS_VERSION} < 099983)
_PKG_JVM_DEFAULT?=	openjdk8
.  elif !empty(MACHINE_PLATFORM:MNetBSD-8.*-i386) || \
	!empty(MACHINE_PLATFORM:MNetBSD-8.*-x86_64)
_PKG_JVM_DEFAULT?=	openjdk11
.  elif !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || \
	!empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || \
	!empty(MACHINE_PLATFORM:MNetBSD-*-earmv[67]hf) || \
	!empty(MACHINE_PLATFORM:MNetBSD-*-aarch64)
_PKG_JVM_DEFAULT?=	openjdk17
.  elif ${MACHINE_PLATFORM:MLinux-*-aarch64} || \
        ${MACHINE_PLATFORM:MLinux-*-x86_64} || \
        ${MACHINE_PLATFORM:MDarwin-*-aarch64} || \
        ${MACHINE_PLATFORM:MDarwin-*-x86_64}
_PKG_JVM_DEFAULT?=	oracle-jdk17
.  elif ${MACHINE_PLATFORM:MLinux-*-i[3456]86}
_PKG_JVM_DEFAULT?=	oracle-jdk8
.  elif !empty(MACHINE_PLATFORM:MSunOS-5.11-i386)
_PKG_JVM_DEFAULT?=	openjdk8
.  elif !empty(MACHINE_PLATFORM:MSunOS-5.11-x86_64)
_PKG_JVM_DEFAULT?=	openjdk8
.  elif !empty(MACHINE_PLATFORM:MDragonFly-*-*)
_PKG_JVM_DEFAULT?=	openjdk8
.  elif !empty(MACHINE_PLATFORM:MFreeBSD-*-*)
_PKG_JVM_DEFAULT?=	openjdk8
.  else
_PKG_JVM_DEFAULT?=	kaffe
.  endif
.endif

# These lists are copied from the JVM package Makefiles.
_ONLY_FOR_PLATFORMS.kaffe= \
	*-*-alpha *-*-arm *-*-arm32 *-*-i386 *-*-m68k \
	*-*-mipsel* *-*-sparc *-*-powerpc
_ONLY_FOR_PLATFORMS.sun-jdk7= \
	Darwin-9.*-i386			Darwin-[1-9][0-9].*-i386	\
        Darwin-9.*-x86_64		Darwin-[1-9][0-9].*-x86_64 	\
	FreeBSD-6.*-i386 \
	Linux-*-i[3-6]86 \
	Linux-*-x86_64 \
	NetBSD-[6-9].*-x86_64		NetBSD-1[0-9].*-x86_64		\
	NetBSD-[6-9].*-i386		NetBSD-1[0-9].*-i386		\
	SunOS-5.11-i386 \
	SunOS-5.11-x86_64
_ONLY_FOR_PLATFORMS.oracle-jdk8= \
	Darwin-9.*-i386			Darwin-[1-9][0-9].*-i386	\
        Darwin-9.*-x86_64		Darwin-[1-9][0-9].*-x86_64 	\
	FreeBSD-6.*-i386 \
	Linux-*-i[3-6]86 \
	Linux-*-x86_64 \
	NetBSD-[6-9].*-x86_64		NetBSD-1[0-9].*-x86_64		\
	NetBSD-[6-9].*-i386		NetBSD-1[0-9].*-i386		\
	SunOS-5.11-x86_64
_ONLY_FOR_PLATFORMS.adoptopenjdk11-bin= \
	Linux-*-x86_64 \
	NetBSD-[6-9].*-x86_64		NetBSD-1[0-9].*-x86_64
_ONLY_FOR_PLATFORMS.openjdk-bin= \
	Linux-*-x86_64 \
	NetBSD-[6-9].*-x86_64		NetBSD-1[0-9].*-x86_64
_ONLY_FOR_PLATFORMS.openjdk8= \
	DragonFly-*-* \
	Linux-*-x86_64			Linux-*-i[3-6]86		\
	NetBSD-[7-9].*-x86_64		NetBSD-1[0-9].*-x86_64		\
	NetBSD-[7-9].*-i386		NetBSD-1[0-9].*-i386		\
	NetBSD-[7-9].*-sparc64		NetBSD-1[0-9].*-sparc64		\
	NetBSD-[8-9].*-aarch64		NetBSD-1[0-9].*-aarch64		\
        NetBSD-[8-9].*-earmv[67]hf	NetBSD-1[0-9].*-earmv[67]hf	\
	SunOS-*-x86_64			SunOS-*-i386			\
	FreeBSD-10.*-x86_64
_ONLY_FOR_PLATFORMS.openjdk11= \
	NetBSD-[8-9].*-x86_64		NetBSD-1[0-9].*-x86_64		\
        NetBSD-[8-9].*-i386		NetBSD-1[0-9].*i386		\
	NetBSD-9.99.*-aarch64		NetBSD-1[0-9].*-aarch64		\
        NetBSD-9.99.*-earmv[67]hf	NetBSD-1[0-9].*-earmv[67]hf
_ONLY_FOR_PLATFORMS.openjdk17= \
	NetBSD-9.*-x86_64		NetBSD-1[0-9].*-x86_64		\
        NetBSD-9.*-i386			NetBSD-1[0-9].*-i386		\
	NetBSD-9.99.*-aarch64		NetBSD-1[0-9].*-aarch64		\
        NetBSD-9.99.*-earmv[67]hf	NetBSD-1[0-9].*-earmv[67]hf
_ONLY_FOR_PLATFORMS.oracle-jdk17= \
	NetBSD-9.*-x86_64		NetBSD-1[0-9].*-x86_64		\
	Darwin-*-aarch64		Darwin-*-x86_64			\
	Linux-*-aarch64			Linux-*-x86_64

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

_JAVA_PKGBASE.kaffe=		kaffe
_JAVA_PKGBASE.openjdk8=		openjdk8
_JAVA_PKGBASE.sun-jdk7=		sun-jre7
_JAVA_PKGBASE.oracle-jdk8=	oracle-jre8
_JAVA_PKGBASE.adoptopenjdk11-bin=	adoptopenjdk11-bin
_JAVA_PKGBASE.openjdk-bin=	openjdk-bin
_JAVA_PKGBASE.openjdk11=	openjdk11
_JAVA_PKGBASE.openjdk17=	openjdk17
_JAVA_PKGBASE.oracle-jdk17=	oracle-jdk17

# The following is copied from the respective JVM Makefiles.
_JAVA_NAME.kaffe=		kaffe
_JAVA_NAME.openjdk8=		openjdk8
_JAVA_NAME.sun-jdk7=		sun7
_JAVA_NAME.oracle-jdk8=		oracle8
_JAVA_NAME.adoptopenjdk11-bin=		adoptopenjdk11-bin
_JAVA_NAME.openjdk-bin=		openjdk-bin
_JAVA_NAME.openjdk11=		openjdk11
_JAVA_NAME.openjdk17=		openjdk17
_JAVA_NAME.oracle-jdk17=	oracle-jdk17

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
PKG_FAIL_REASON+=	"no acceptable JVM found"
_PKG_JVM=		"none"
.endif

BUILDLINK_API_DEPENDS.kaffe?=		kaffe>=1.1.4
BUILDLINK_API_DEPENDS.openjdk8?=	openjdk8-[0-9]*
BUILDLINK_API_DEPENDS.sun-jdk7?=	sun-jdk7-[0-9]*
BUILDLINK_API_DEPENDS.sun-jre7?=	sun-jre7-[0-9]*
BUILDLINK_API_DEPENDS.oracle-jdk8?=	oracle-jdk8-[0-9]*
BUILDLINK_API_DEPENDS.oracle-jre8?=	oracle-jre8-[0-9]*
BUILDLINK_API_DEPENDS.adoptopenjdk11-bin?=	adoptopenjdk11-bin-[0-9]*
BUILDLINK_API_DEPENDS.openjdk-bin?=	openjdk-bin-[0-9]*
BUILDLINK_API_DEPENDS.openjdk11?=	openjdk11-[0-9]*
BUILDLINK_API_DEPENDS.openjdk17?=	openjdk17-[0-9]*
BUILDLINK_API_DEPENDS.oracle-jdk17?=	oracle-jdk17-[0-9]*

_JRE.kaffe=		kaffe
_JRE.openjdk8=		openjdk8
_JRE.sun-jdk7=		sun-jre7
_JRE.oracle-jdk8=	oracle-jre8
_JRE.adoptopenjdk11-bin=	adoptopenjdk11-bin
_JRE.openjdk-bin=	openjdk-bin
_JRE.openjdk11=		openjdk11
_JRE.openjdk17=		openjdk17
_JRE.oracle-jdk17=	oracle-jdk17

_JAVA_BASE_CLASSES=	classes.zip

.if ${_PKG_JVM} == "kaffe"
_JDK_PKGSRCDIR=		../../lang/kaffe
_JRE_PKGSRCDIR=		${_JDK_PKGSRCDIR}
_JAVA_HOME=		${LOCALBASE}/java/kaffe
.elif ${_PKG_JVM} == "openjdk8"
_JDK_PKGSRCDIR=		../../lang/openjdk8
_JRE_PKGSRCDIR=		${_JDK_PKGSRCDIR}
_JAVA_HOME=		${LOCALBASE}/java/openjdk8
.elif ${_PKG_JVM} == "sun-jdk7"
_JDK_PKGSRCDIR=		../../lang/sun-jdk7
_JRE_PKGSRCDIR=		../../lang/sun-jre7
_JAVA_HOME=		${LOCALBASE}/java/sun-7
UNLIMIT_RESOURCES+=	datasize virtualsize
.elif ${_PKG_JVM} == "oracle-jdk8"
_JDK_PKGSRCDIR=		../../lang/oracle-jdk8
_JRE_PKGSRCDIR=		../../lang/oracle-jre8
_JAVA_HOME=		${LOCALBASE}/java/oracle-8
UNLIMIT_RESOURCES+=	datasize virtualsize
.elif ${_PKG_JVM} == "adoptopenjdk11-bin"
_JDK_PKGSRCDIR=		../../lang/adoptopenjdk11-bin
_JRE_PKGSRCDIR=		../../lang/adoptopenjdk11-bin
_JAVA_HOME=		${LOCALBASE}/java/adoptopenjdk11-bin
.elif ${_PKG_JVM} == "openjdk-bin"
_JDK_PKGSRCDIR=		../../lang/openjdk-bin
_JRE_PKGSRCDIR=		../../lang/openjdk-bin
_JAVA_HOME=		${LOCALBASE}/java/openjdk-bin
UNLIMIT_RESOURCES+=	datasize virtualsize
.elif ${_PKG_JVM} == "openjdk11"
_JDK_PKGSRCDIR=		../../lang/openjdk11
_JRE_PKGSRCDIR=		../../lang/openjdk11
_JAVA_HOME=		${LOCALBASE}/java/openjdk11
UNLIMIT_RESOURCES+=	datasize virtualsize
.elif ${_PKG_JVM} == "openjdk17"
_JDK_PKGSRCDIR=		../../lang/openjdk17
_JRE_PKGSRCDIR=		../../lang/openjdk17
_JAVA_HOME=		${LOCALBASE}/java/openjdk17
UNLIMIT_RESOURCES+=	datasize virtualsize
.elif ${_PKG_JVM} == "oracle-jdk17"
_JDK_PKGSRCDIR=		../../lang/oracle-jdk17
_JRE_PKGSRCDIR=		../../lang/oracle-jdk17
_JAVA_HOME=		${LOCALBASE}/java/oracle-jdk17
UNLIMIT_RESOURCES+=	datasize virtualsize
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
ALL_ENV+=		JAVA_HOME=${PKG_JAVA_HOME:Q}
BUILD_DEFS+=		${_USER_VARS.java}
BUILD_DEFS_EFFECTS+=	${_SYS_VARS.java}
MAKEFLAGS+=		PKG_JVM=${PKG_JVM:Q}
PREPEND_PATH+=		${PKG_JAVA_HOME}/bin
JAVA_BINPREFIX=		${LOCALBASE}/bin/${_JAVA_NAME.${_PKG_JVM}}

PLIST_SUBST+=		PKG_JAVA_HOME=${PKG_JAVA_HOME:Q}
FILES_SUBST+=		PKG_JAVA_HOME=${PKG_JAVA_HOME:Q}

.endif	# JAVA_VM_MK
