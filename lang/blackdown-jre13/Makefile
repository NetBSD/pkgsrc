# $NetBSD: Makefile,v 1.1.1.1 2002/07/27 22:39:50 jschauma Exp $
#

BASENAME=		j2re
PKGNAME=		blackdown-jre13-1
.if ${MACHINE_ARCH} == "arm"
DISTNAME=     		${BASENAME}-RC1-linux-arm
.elif ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "sparc"
DISTNAME=		${EXTNAME}-${MACHINE_ARCH}
.elif ${MACHINE_ARCH} == "powerpc"
DISTFILES=		${EXTNAME}-ppc
.endif

COMMENT=        Blackdown's Java(tm) Runtime Environment 1.3.1

ONLY_FOR_PLATFORM+= NetBSD-*-arm Linux-*-arm

.include "../../lang/blackdown-jre13/Makefile.common"
.include "../../mk/bsd.pkg.mk"
