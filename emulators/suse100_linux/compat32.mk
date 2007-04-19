# $NetBSD: compat32.mk,v 1.3 2007/04/19 21:25:28 xtraeme Exp $
#

.ifndef SUSE_LINUX_COMPAT32_MK
SUSE_LINUX_COMPAT32_MK=	# defined

.  if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "x86_64"

#
# We must protect this part with packages that are using
# the options framework, otherwise we'll end executing two
# targets for the options.
#
.  ifndef SUSE_COMPAT32_OPT
PKG_OPTIONS_VAR=	PKG_OPTIONS.suse
PKG_SUPPORTED_OPTIONS=	compat32

.    include "../../mk/bsd.options.mk"
.  else
ONLY_FOR_PLATFORM:=	${ONLY_FOR_PLATFORM} NetBSD-*-x86_64
#MACHINE_ARCH:=		i386
DEPENDS:=		${DEPENDS:S/suse/suse32/}
EMULSUBDIR:=		emul/linux32
.  endif

STRING_ERROR1=		\
	"This package is not compatible with x86_64 without using "
STRING_ERROR2=		\
	"PKG_OPTIONS.suse=compat32."
MYSTRING=		${STRING_ERROR1}${STRING_ERROR2}

.    if !empty(PKG_OPTIONS:Mcompat32)
#
# We don't need to override the following vars in packages using
# SUSE_COMPAT32, because this is only required for the suse 
# packages.
#
.      ifndef SUSE_COMPAT32
#
# Override required vars
#
PKGNAME:=		${DISTNAME:S/suse/suse32/}
COMMENT:=		${COMMENT:S/Linux/Linux 32/}
SUSE_ARCH:=		i586
.      endif
#
# This is common for all linux packages.
#
MACHINE_ARCH:=		i386
ARCH:=			${MACHINE_ARCH}
DEPENDS:=		${DEPENDS:S/suse/suse32/}
LINUX_LIB:=		lib
BINSUFFIX:=		# empty
#
# Use the correct directories.
#
OPSYS_EMULSUBDIR=	linux32
SUSE_COMPAT32_SUFFIX=	32
EMULSUBDIR:=		emul/linux32
.    else
OPSYS_EMULSUBDIR=	linux
SUSE_COMPAT32_SUFFIX=	# empty
.      if defined(ONLY_FOR_PLATFORM) && \
	    empty(ONLY_FOR_PLATFORM:MNetBSD-*-x86_64)
PKG_FAIL_REASON+=	${MYSTRING}
.      endif
.    endif # end of PKG_OPTIONS.suse=compat32
.  endif # end of NetBSD && x86_64
#
# This is to avoid to use the same code on every package
# many times.
#
.  ifdef SUSE_INCLUDE_MAKEFILE_ARCH
.    if exists(Makefile.${MACHINE_ARCH})
.      include "Makefile.${MACHINE_ARCH}"
.    endif
.  endif

.endif # end of SUSE_LINUX_COMPAT32_MK
