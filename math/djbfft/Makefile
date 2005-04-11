# $NetBSD: Makefile,v 1.8 2005/04/11 21:46:28 tv Exp $

DISTNAME=       	djbfft-0.76
CATEGORIES=     	math
MASTER_SITES=   	http://cr.yp.to/djbfft/

MAINTAINER=     	tech-pkg@NetBSD.org
HOMEPAGE=       	http://pobox.com/~djb/djbfft.html
COMMENT=        	Extremely fast library for floating-point convolution


DJB_RESTRICTED=		YES
NOT_FOR_PLATFORM=	IRIX-*-*

.ifdef(WITH_OPT_PENTIUM)
DJB_CONFIG_CMDS=	${ECHO} pentium > conf-opt
.endif
.ifdef(WITH_OPT_PPRO)
DJB_CONFIG_CMDS=	${ECHO} ppro > conf-opt
.endif
.if (${MACHINE_ARCH} == "sparc")
DJB_CONFIG_CMDS=	${ECHO} sparc > conf-opt
.endif

post-extract:
.if (${MACHINE_ARCH} == "i386" && !WITH_OPT_PENTIUM)
	@${ECHO} '===> Set WITH_OPT_PENTIUM to optimize for both Pentium and Pentium MMX'
	@${ECHO} '     like processors.'
.endif
.if (${MACHINE_ARCH} == "i386" && !WITH_OPT_PPRO)
	@${ECHO} '===> Set WITH_OPT_PPRO to optimize for Pentium Pro, Pentium II, and'
	@${ECHO} '     Pentium III like processors.'
.endif

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
