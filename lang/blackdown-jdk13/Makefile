# $NetBSD: Makefile,v 1.8 2002/07/27 22:45:08 jschauma Exp $
#

BASENAME=		j2sdk
PKGNAME=		blackdown-jdk13-1
PKGREVISION=	1

DEPENDS=		blackdown-jre13>=1:../../lang/blackdown-jre13

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "sparc"
DISTNAME=		${EXTNAME}-${MACHINE_ARCH}
.elif ${MACHINE_ARCH} == "powerpc"
DISTNAME=		${EXTNAME}-ppc
DEPENDS+=		linuxppc_lib>=2000.4.2:../../emulators/linuxppc_lib
.endif

# these are part of JRE
do-configure:
	@${RM} -r ${WRKSRC}/jre ${WRKSRC}/LICENSE ${WRKSRC}/CHANGES \
				${WRKSRC}/COPYRIGHT ${WRKSRC}/README ${WRKSRC}/INSTALL

.include "../../lang/blackdown-jre13/Makefile.common"
.include "../../mk/bsd.pkg.mk"
