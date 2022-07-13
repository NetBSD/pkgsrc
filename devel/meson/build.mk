# $NetBSD: build.mk,v 1.15 2022/07/13 03:57:22 triaxx Exp $

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

.if !defined(USE_CMAKE)
MAKE_ENV+=	CMAKE=${TOOLS_PATH.false}
.endif

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])

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
	${RUN}${ECHO} '[properties]' >$@.tmp
.  for _v_ in ${MESON_CROSS_VARS}
.    if defined(MESON_CROSS.${_v_})
	${RUN}${ECHO} ${_v_} = ${MESON_CROSS.${_v_}:Q} >>$@.tmp
.    endif
.  endfor
.  for _v_ in ${MESON_CROSS_OPSYS_VARS}
.    if defined(MESON_CROSS.${OPSYS}.${_v_})
	${RUN}${ECHO} ${_v_} = ${MESON_CROSS.${OPSYS}.${_v_}:Q} >>$@.tmp
.    endif
.  endfor
.  for _v_ in ${MESON_CROSS_ARCH_VARS}
.    if defined(MESON_CROSS.${MACHINE_ARCH}.${_v_})
	${RUN}${ECHO} ${_v_} = ${MESON_CROSS.${MACHINE_ARCH}.${_v_}:Q} >>$@.tmp
.    endif
.  endfor
	${RUN}${ECHO} '[host_machine]' >>$@.tmp
	${RUN}${ECHO} "system = '${LOWER_OPSYS}'" >>$@.tmp
	${RUN}${ECHO} "cpu_family = '${MESON_CPU_FAMILY}'" >>$@.tmp
	${RUN}${ECHO} "cpu = '${MESON_CPU}'" >>$@.tmp
	${RUN}${ECHO} "endian = '${MESON_CPU_ENDIAN}'" >>$@.tmp
	${RUN}${MV} -f $@.tmp $@
MESON_CROSS_ARGS+=	--cross-file ${MESON_CROSS_FILE:Q}

.endif

do-configure: meson-configure
meson-configure:
.for d in ${CONFIGURE_DIRS}
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${MAKE_ENV} meson \
		--prefix ${PREFIX} \
		--libdir lib \
		--libexecdir libexec \
		--mandir ${PKGMANDIR} \
		--sysconfdir ${PKG_SYSCONFDIR} \
		${MESON_CROSS_ARGS} \
		--buildtype=plain ${MESON_ARGS} . output
.endfor

do-build: meson-build
meson-build:
.for d in ${BUILD_DIRS}
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${MAKE_ENV} ninja -j ${_MAKE_JOBS_N:U1} -C output
.endfor

do-install: meson-install
meson-install:
.for d in ${INSTALL_DIRS}
	if [ -f ${WRKSRC}/meson_post_install.py ]; then		\
		${CHMOD} +x ${WRKSRC}/meson_post_install.py;	\
	fi
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ninja -j ${_MAKE_JOBS_N:U1} -C output install
.endfor

do-test: meson-test
meson-test:
.for d in ${TEST_DIRS}
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${TEST_ENV} \
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
_USER_VARS.meson=	MAKE_JOBS PKG_SYSCONFDIR
_USE_VARS.meson=	TOOLS_PATH.false WRKSRC PREFIX PKGMANDIR
_USE_VARS.meson+=	_MAKE_JOBS_N
_DEF_VARS.meson=	TOOL_DEPENDS
_LISTED_VARS.meson=	*_ARGS *_DEPENDS
_SORTED_VARS.meson=	*_ENV
