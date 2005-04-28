# $NetBSD: arch.mk,v 1.7 2005/04/28 23:11:14 jlam Exp $
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
.  else
_PVM_ARCH=	# empty
.  endif
.elif ${OPSYS} == "SunOS"
_PVM_OPSYS=	SUN4
_PVM_ARCH=	SOL2	# Solaris (SunOS 5.*)
.elif ${OPSYS} == "Darwin"
_PVM_OPSYS=    DARWIN
_PVM_ARCH=     # empty
.else
_PVM_OPSYS=	UNKNOWN
_PVM_ARCH=	# empty
.endif

PVM_ARCH=	${_PVM_OPSYS}${_PVM_ARCH}
PLIST_SUBST+=	PVM_ARCH=${PVM_ARCH}
FILES_SUBST+=	PVM_ARCH=${PVM_ARCH}
