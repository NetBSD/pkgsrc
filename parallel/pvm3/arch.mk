# $NetBSD: arch.mk,v 1.12 2012/02/03 04:06:08 sbd Exp $
#

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
_PVM_OPSYS=	NETBSD
_PVM_ARCH_cmd=	${ECHO} ${MACHINE_ARCH} | ${TR} "[a-z]" "[A-Z]"
_PVM_ARCH=	${_PVM_ARCH_cmd:sh}
.elif ${OPSYS} == "Linux"
_PVM_OPSYS=	LINUX
.  if !empty(MACHINE_ARCH:Malpha*)
_PVM_ARCH=	ALPHA
.  elif !empty(MACHINE_ARCH:Marm*)
_PVM_ARCH=	ARM
.  elif !empty(MACHINE_ARCH:Msparc*)
_PVM_ARCH=	SPARC
.  elif !empty(MACHINE_ARCH:Mhp_pa*)
_PVM_ARCH=	HPPA
.  elif !empty(MACHINE_ARCH:Mppc*)
_PVM_ARCH=	PPC
.  elif !empty(MACHINE_ARCH:Mx86_64)
_PVM_ARCH=	64
.  else
_PVM_ARCH=	# empty
.  endif
.elif ${OPSYS} == "SunOS"
.  if !empty(MACHINE_ARCH:Mi386*) || !empty(MACHINE_ARCH:Mx86_64*)
_PVM_OPSYS=	X86
.  else
_PVM_OPSYS=	SUN4
.  endif
_PVM_ARCH=	SOL2	# Solaris (SunOS 5.*)
.elif ${OPSYS} == "Darwin"
_PVM_OPSYS=    DARWIN
_PVM_ARCH=     # empty
.elif ${OPSYS} == "DragonFly"
_PVM_OPSYS=	DRAGONFLY
_PVM_ARCH=	# empty
.elif ${OPSYS} == "FreeBSD"
_PVM_OPSYS=	FREEBSD
_PVM_ARCH=	# empty
.else
_PVM_OPSYS=	UNKNOWN
_PVM_ARCH=	# empty
.endif

PVM_ARCH=	${_PVM_OPSYS}${_PVM_ARCH}
PLIST_SUBST+=	PVM_ARCH=${PVM_ARCH:Q}
FILES_SUBST+=	PVM_ARCH=${PVM_ARCH:Q}
