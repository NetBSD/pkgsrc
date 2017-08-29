# $NetBSD: platform.mk,v 1.4 2017/08/29 14:47:35 jmcneill Exp $
#

#
# Common definition for ruby*-base package.
#

.if !defined(_RUBY_PLATFORM_MK)
_RUBY_PLATFORM_MK=	# defined

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/compiler.mk"

MAKE_DIRS+=	${RUBY_SITEARCHLIB} ${RUBY_VENDORARCHLIB} ${RUBY_SITERIDIR}
FILES_SUBST+=	DATE=${DATE:Q}

REQD_DIRS+=	${GEM_HOME}/cache
REQD_DIRS+=	${GEM_HOME}/doc

#
# substitute path in rubygems.
#
SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	lib/rubygems/config_file.rb
SUBST_SED.conf=		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.conf=	Fixing configuration files.

#
# Don't reference pkgsrc's INSTALL macro since Ruby expect it could
# execute by unprivileged user.
#
CONFIGURE_ENV+=	INSTALL="${INSTALL} ${COPY}" \
		INSTALL_DATA= INSTALL_PROGRAM= INSTALL_SCRIPT=
CONFIGURE_ENV+= ac_cv_prog_PKG_CONFIG=""

#
# prevent unwanted mkdir recorded in rbconfig.rb
#
CONFIGURE_ENV+=	MKDIR_P=${MKDIR:Q}

# Ruby build process depends on config.status's content
CONFIG_STATUS_OVERRIDE=	# empty

########
#
# Platform
#

#
# Darwin
#
# Don't like Apple's builtin OpenSSL.
#
.if ${OPSYS} == "Darwin"
USE_BUILTIN.openssl=	no
.endif

#
# DragonFly
#
#
# Work around for getucontext(3)
#
.if ${OPSYS} == "DragonFly" && ${OS_VERSION} == "1.8.0"
CONFIGURE_ENV+=	ac_cv_header_ucontext_h=no
.endif

#
# Linux
#
# /usr/bin/dtrace is not DTrace.
#
.if ${OPSYS} == "Linux" && exists(/usr/bin/dtrace)
CONFIGURE_ARGS+=	--disable-dtrace
.endif

#
# NetBSD
#
# dtrace support has problem on i386.  (No official NetBSD release is
# built with dtrace enabled yet, so this problem is on 7.99.* only.)
#
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--disable-dtrace
.endif

#
# NetBSD
#
# dtrace support can cause problems with miniruby on arm.
#
.if !empty(MACHINE_PLATFORM:MNetBSD-*-*arm*)
CONFIGURE_ARGS+=	--disable-dtrace
.endif

#
# Solaris
#
# fix build with sunpro.
#
.if !empty(PKGSRC_COMPILER:Msunpro)
LIBS.SunOS+=	-B static -lsunmath -B dynamic -lm
LDFLAGS.SunOS+=	-L${SUNWSPROBASE}/lib -Wl,-R${SUNWSPROBASE}/lib
CONFIGURE_ENV+=	LDSHARED="${CC} -G"
.else
LIBS.SunOS+=	-lm
.endif

CONFIGURE_ENV.SunOS+=	OBJCOPY=:

#
# MirBSD
#
# if present, an unsupported sysconf call is used
#
CONFIGURE_ENV.MirBSD+=	ac_cv_func_getgrnam_r=no

# On platforms where DTrace is available, we need to invoke dtrace(1)
# with the original PATH. Otherwise it gets confused in the presence
# of our cc wrapper because it tries to invoke the system-default gcc
# with argv[0] set to "gcc", not the absolute path to gcc.
.if exists(/usr/sbin/dtrace)
post-wrapper:
	${RUN}(${ECHO} '#!${SH}'; \
		${ECHO} 'PATH=/bin:/usr/bin:/sbin:/usr/sbin; export PATH'; \
		${ECHO} '/usr/sbin/dtrace $$@') \
		> "${WRAPPER_BINDIR}/dtrace"
	${RUN}${CHMOD} +x "${WRAPPER_BINDIR}/dtrace"
.endif
#
# bmake doesn't like the codesign/POSTLINK constructs for Darwin.
#
.if ${OPSYS} == "Cygwin" || ${OPSYS} == "Darwin"
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
.endif

########
#
# PLIST
#

# Win32 support (for Cygwin)
#
PLIST_VARS+=	win32
.if ${OPSYS} == "Cygwin"
PLIST.win32=	yes
.endif

#
# IRIX work around which should be fixed.
#
PLIST_VARS+=	io
.if ${OPSYS} != "IRIX"
PLIST.io=	yes
.endif

.endif # _RUBY_REPLACE_MK
