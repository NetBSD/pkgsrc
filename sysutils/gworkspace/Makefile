# $NetBSD: Makefile,v 1.2 2003/03/07 07:34:43 jmc Exp $
#

.include "Makefile.common"

COMMENT=	GNUstep Workspace manager

pre-install:
	${CP} ${FILESDIR}/GNUmakefile ${WRKSRC}/GWLib

#
# Gnustep seems to use it's own idea of architecture names and at least for
# i386 is using ix86. For other archs default for MACHINE_ARCH.
# Tested specifically on x86 and powerpc
.if (${MACHINE_ARCH} == "i386")
PLIST_SUBST+=   ARCH="ix86"
PLIST_SUBST+=   ARCH_LOC="ix86/${LOWER_OPSYS}elf"
.else
PLIST_SUBST+=   ARCH="${MACHINE_ARCH}"
PLIST_SUBST+=   ARCH_LOC="${MACHINE_ARCH}/${LOWER_OPSYS}"
.endif

.include "../../sysutils/GWLib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
