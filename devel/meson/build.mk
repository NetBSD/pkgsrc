# $NetBSD: build.mk,v 1.27 2024/05/19 05:37:11 wiz Exp $

MESON_REQD?=	0
.for version in ${MESON_REQD}
TOOL_DEPENDS+=	meson>=${version}:../../devel/meson
.endfor

CONFIGURE_DIRS?=	.
BUILD_DIRS?=		${CONFIGURE_DIRS}
INSTALL_DIRS?=		${CONFIGURE_DIRS}
TEST_DIRS?=		${CONFIGURE_DIRS}

.PHONY: meson-configure meson-build meson-install meson-test

# pkgsrc contains multiple llvm-config executables at multiple locations.
.if !empty(LLVM_CONFIG_PATH)
MAKE_ENV+=	LLVM_CONFIG_PATH=${LLVM_CONFIG_PATH:Q}
.endif

# Prevent use of "response files" that break pkgsrc wrappers.
# The default threshold of 64k is too low for pkgsrc.
MAKE_ENV+=	MESON_RSP_THRESHOLD=262144

.if !defined(USE_CMAKE) && empty(USE_TOOLS:Mcmake)
MAKE_ENV+=	CMAKE=${TOOLS_PATH.false}
.endif

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:U:tl} == yes

MESON_CPU_FAMILY.amd64=		x86_64
MESON_CPU_FAMILY.arm26?=	arm
MESON_CPU_FAMILY.arm32?=	arm
MESON_CPU_FAMILY.earm?=		arm
MESON_CPU_FAMILY.earmeb?=	arm
MESON_CPU_FAMILY.earmhf?=	arm
MESON_CPU_FAMILY.earmhfeb?=	arm
MESON_CPU_FAMILY.earmv4?=	arm
MESON_CPU_FAMILY.earmv4eb?=	arm
MESON_CPU_FAMILY.earmv5?=	arm
MESON_CPU_FAMILY.earmv5eb?=	arm
MESON_CPU_FAMILY.earmv6?=	arm
MESON_CPU_FAMILY.earmv6eb?=	arm
MESON_CPU_FAMILY.earmv6hf?=	arm
MESON_CPU_FAMILY.earmv6hfeb?=	arm
MESON_CPU_FAMILY.earmv7?=	arm
MESON_CPU_FAMILY.earmv7eb?=	arm
MESON_CPU_FAMILY.earmv7hf?=	arm
MESON_CPU_FAMILY.earmv7hfeb?=	arm
MESON_CPU_FAMILY.i386=		x86
MESON_CPU_FAMILY.i486=		x86
MESON_CPU_FAMILY.i586=		x86
MESON_CPU_FAMILY.i686=		x86
MESON_CPU_FAMILY.hppa=		parisc
MESON_CPU_FAMILY.m68000=	m68k
MESON_CPU_FAMILY.mips64eb=	mips
MESON_CPU_FAMILY.mips64el=	mips
MESON_CPU_FAMILY.mipseb=	mips
MESON_CPU_FAMILY.mipsel=	mips
MESON_CPU_FAMILY.powerpc64=	ppc64
MESON_CPU_FAMILY.powerpc=	ppc
MESON_CPU_FAMILY.sh3eb=		sh3
MESON_CPU_FAMILY.sh3el=		sh3

MESON_CPU_ENDIAN.earmeb?=	big
MESON_CPU_ENDIAN.earmhfeb?=	big
MESON_CPU_ENDIAN.earmv4eb?=	big
MESON_CPU_ENDIAN.earmv5eb?=	big
MESON_CPU_ENDIAN.earmv6eb?=	big
MESON_CPU_ENDIAN.earmv6hfeb?=	big
MESON_CPU_ENDIAN.earmv7eb?=	big
MESON_CPU_ENDIAN.earmv7hfeb?=	big
MESON_CPU_ENDIAN.mips64eb=	big
MESON_CPU_ENDIAN.mipseb=	big
MESON_CPU_ENDIAN.powerpc64=	big
MESON_CPU_ENDIAN.powerpc=	big
MESON_CPU_ENDIAN.sh3eb=		big
MESON_CPU_ENDIAN.sparc64=	big
MESON_CPU_ENDIAN.sparc=		big

MESON_CPU_FAMILY=	${MESON_CPU_FAMILY.${MACHINE_ARCH}:U${MACHINE_ARCH}}
MESON_CPU=		${MACHINE_ARCH}
MESON_CPU_ENDIAN=	${MESON_CPU_ENDIAN.${MACHINE_ARCH}:Ulittle}

MESON_CROSS_VARS+=	sys_root
MESON_CROSS.sys_root=	'${_CROSS_DESTDIR}'

MESON_CROSS_FILE=	${WRKDIR}/.meson_cross
meson-configure: ${MESON_CROSS_FILE}
${MESON_CROSS_FILE}:
	@${STEP_MSG} Creating meson cross file
	${RUN}${ECHO} '[properties]' >${.TARGET}.tmp
.  for _v_ in ${MESON_CROSS_VARS}
.    if defined(MESON_CROSS.${_v_})
	${RUN}${ECHO} ${_v_} = ${MESON_CROSS.${_v_}:Q} >>${.TARGET}.tmp
.    endif
.  endfor
.  for _v_ in ${MESON_CROSS_OPSYS_VARS}
.    if defined(MESON_CROSS.${OPSYS}.${_v_})
	${RUN}${ECHO} ${_v_} = ${MESON_CROSS.${OPSYS}.${_v_}:Q} \
		>>${.TARGET}.tmp
.    endif
.  endfor
.  for _v_ in ${MESON_CROSS_ARCH_VARS}
.    if defined(MESON_CROSS.${MACHINE_ARCH}.${_v_})
	${RUN}${ECHO} ${_v_} = ${MESON_CROSS.${MACHINE_ARCH}.${_v_}:Q} \
		>>${.TARGET}.tmp
.    endif
.  endfor
	${RUN}${ECHO} '[host_machine]' >>${.TARGET}.tmp
	${RUN}${ECHO} "system = '${LOWER_OPSYS}'" >>${.TARGET}.tmp
	${RUN}${ECHO} "cpu_family = '${MESON_CPU_FAMILY}'" >>${.TARGET}.tmp
	${RUN}${ECHO} "cpu = '${MESON_CPU}'" >>${.TARGET}.tmp
	${RUN}${ECHO} "endian = '${MESON_CPU_ENDIAN}'" >>${.TARGET}.tmp
	${RUN}${ECHO} '[binaries]' >>${.TARGET}.tmp
.  for _v_ in ${MESON_CROSS_BINARIES}
.    if defined(MESON_CROSS_BINARY.${_v_})
	${RUN}${ECHO} ${_v_} = \'${MESON_CROSS_BINARY.${_v_}:Q}\' \
		>>${.TARGET}.tmp
.    endif
.  endfor
	${RUN}${MV} -f ${.TARGET}.tmp ${.TARGET}
MESON_CROSS_ARGS+=	--cross-file ${MESON_CROSS_FILE:Q}

.endif				# ${USE_CROSS_COMPILE:U:tl} == yes

do-configure: meson-configure
meson-configure:
.for d in ${CONFIGURE_DIRS}
.  if ${CONFIGURE_DIRS:[#]} != 1
	@${STEP_MSG} Configuring meson in ${d}
.  endif
	${RUN}cd ${WRKSRC} && cd ${d} && ${SETENV} ${MAKE_ENV} meson setup \
		--prefix ${PREFIX} \
		--libdir lib \
		--libexecdir libexec \
		--mandir ${PKGMANDIR} \
		--sysconfdir ${PKG_SYSCONFDIR} \
		--wrap-mode=nodownload \
		${MESON_CROSS_ARGS} \
		--buildtype=plain ${MESON_ARGS} . output
.endfor

do-build: meson-build
meson-build:
.for d in ${BUILD_DIRS}
.  if ${BUILD_DIRS:[#]} != 1
	@${STEP_MSG} Building with ninja in ${d}
.  endif
	${RUN}cd ${WRKSRC} && cd ${d} && ${SETENV} ${MAKE_ENV} \
	    ninja -j ${_MAKE_JOBS_N:U1} -C output
.endfor

.if empty(MESON_INSTALL:Mno)
do-install: meson-install
meson-install:
.  for d in ${INSTALL_DIRS}
	${RUN}if [ -f ${WRKSRC}/meson_post_install.py ]; then	\
		${CHMOD} +x ${WRKSRC}/meson_post_install.py;	\
	fi
.    if ${INSTALL_DIRS:[#]} != 1
	@${STEP_MSG} Installing with ninja in ${d}
.    endif
	${RUN}cd ${WRKSRC} && cd ${d} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ninja -j ${_MAKE_JOBS_N:U1} -C output install
.  endfor
.endif

do-test: meson-test
meson-test:
.for d in ${TEST_DIRS}
.  if ${TEST_DIRS:[#]} != 1
	@${STEP_MSG} Testing with ninja in ${d}
.  endif
	${RUN}cd ${WRKSRC} && cd ${d} && ${SETENV} ${TEST_ENV} \
	    ninja -j ${_MAKE_JOBS_N:U1} -C output test
.endfor

_VARGROUPS+=		meson
_PKG_VARS.meson=	MESON_REQD
_PKG_VARS.meson+=	CONFIGURE_DIRS
_PKG_VARS.meson+=	BUILD_DIRS MAKE_ENV
_PKG_VARS.meson+=	TEST_DIRS TEST_ENV
_PKG_VARS.meson+=	INSTALL_DIRS INSTALL_ENV
_PKG_VARS.meson+=	LLVM_CONFIG_PATH
_PKG_VARS.meson+=	USE_CMAKE MESON_ARGS
_PKG_VARS.meson+=	MESON_CROSS_ARCH_VARS
_PKG_VARS.meson+=	MESON_CROSS_OPSYS_VARS
_PKG_VARS.meson+=	MESON_CROSS_VARS MESON_CROSS.*
_PKG_VARS.meson+=	MESON_CROSS_BINARIES MESON_CROSS_BINARY.*
_USER_VARS.meson=	MAKE_JOBS PKG_SYSCONFDIR
_USE_VARS.meson=	TOOLS_PATH.false WRKDIR WRKSRC PREFIX PKGMANDIR
_USE_VARS.meson+=	MACHINE_ARCH
_USE_VARS.meson+=	LOWER_OPSYS
_USE_VARS.meson+=	OPSYS
_USE_VARS.meson+=	USE_CROSS_COMPILE
_USE_VARS.meson+=	_CROSS_DESTDIR
_USE_VARS.meson+=	_MAKE_JOBS_N
_DEF_VARS.meson+=	MESON_CPU
_DEF_VARS.meson+=	MESON_CPU_ENDIAN
_DEF_VARS.meson+=	MESON_CPU_FAMILY
_DEF_VARS.meson+=	TOOL_DEPENDS
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.earmeb
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.earmhfeb
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.earmv4eb
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.earmv5eb
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.earmv6eb
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.earmv6hfeb
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.earmv7eb
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.earmv7hfeb
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.mips64eb
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.mipseb
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.powerpc
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.powerpc64
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.sh3eb
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.sparc
_IGN_VARS.meson+=	MESON_CPU_ENDIAN.sparc64
_IGN_VARS.meson+=	MESON_CPU_FAMILY.amd64
_IGN_VARS.meson+=	MESON_CPU_FAMILY.arm26
_IGN_VARS.meson+=	MESON_CPU_FAMILY.arm32
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earm
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmeb
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmhf
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmhfeb
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmv4
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmv4eb
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmv5
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmv5eb
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmv6
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmv6eb
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmv6hf
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmv6hfeb
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmv7
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmv7eb
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmv7hf
_IGN_VARS.meson+=	MESON_CPU_FAMILY.earmv7hfeb
_IGN_VARS.meson+=	MESON_CPU_FAMILY.hppa
_IGN_VARS.meson+=	MESON_CPU_FAMILY.i386
_IGN_VARS.meson+=	MESON_CPU_FAMILY.i486
_IGN_VARS.meson+=	MESON_CPU_FAMILY.i586
_IGN_VARS.meson+=	MESON_CPU_FAMILY.i686
_IGN_VARS.meson+=	MESON_CPU_FAMILY.m68000
_IGN_VARS.meson+=	MESON_CPU_FAMILY.mips64eb
_IGN_VARS.meson+=	MESON_CPU_FAMILY.mips64el
_IGN_VARS.meson+=	MESON_CPU_FAMILY.mipseb
_IGN_VARS.meson+=	MESON_CPU_FAMILY.mipsel
_IGN_VARS.meson+=	MESON_CPU_FAMILY.powerpc
_IGN_VARS.meson+=	MESON_CPU_FAMILY.powerpc64
_IGN_VARS.meson+=	MESON_CPU_FAMILY.sh3eb
_IGN_VARS.meson+=	MESON_CPU_FAMILY.sh3el
_IGN_VARS.meson+=	MESON_CROSS.sys_root
_IGN_VARS.meson+=	MESON_CROSS_ARGS
_IGN_VARS.meson+=	MESON_CROSS_FILE
_LISTED_VARS.meson=	*_ARGS *_DEPENDS
_SORTED_VARS.meson=	*_ENV
