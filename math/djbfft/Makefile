# $NetBSD: Makefile,v 1.2 2003/12/24 09:53:49 jmmv Exp $

DISTNAME=       djbfft-0.76
CATEGORIES=     math
MASTER_SITES=   http://cr.yp.to/djbfft/

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=       http://pobox.com/~djb/djbfft.html
COMMENT=        Extremely fast library for floating-point convolution

ALL_TARGET=
INSTALL_TARGET=	setup check

NOT_FOR_PLATFORM=	IRIX-*-*

do-configure:
	@${ECHO} '${CC} ${CFLAGS}' > ${WRKSRC}/conf-cc
	@${ECHO} '${CC}' > ${WRKSRC}/conf-ld
	@${ECHO} ${PREFIX} > ${WRKSRC}/conf-home
.ifdef(WITH_OPT_PENTIUM)
	@${ECHO} 'pentium' > ${WRKSRC}/conf-opt
.endif
.ifdef(WITH_OPT_PPRO)
	@${ECHO} 'ppro' > ${WRKSRC}/conf-opt
.endif
.if (${MACHINE_ARCH} == "sparc")
	@${ECHO} 'sparc' > ${WRKSRC}/conf-opt
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

.include "../../mk/bsd.pkg.mk"
