# $NetBSD: Makefile,v 1.10 2002/08/08 12:20:18 agc Exp $
#

BASENAME=		j2sdk
DISTNAME=		${EXTNAME}-${MACHINE_ARCH}
PKGNAME=		blackdown-jdk13-1
PKGREVISION=	1

COMMENT=		Linux port of the Blackdown Java(tm) Runtime Environment

DEPENDS=		blackdown-jre13>=1:../../lang/blackdown-jre13

.if ${MACHINE_ARCH} == "powerpc"
DISTNAME=		${EXTNAME}-ppc
DEPENDS+=		linuxppc_lib>=2000.4.2:../../emulators/linuxppc_lib
.endif

# these are part of JRE
do-configure:
	@${RM} -r ${WRKSRC}/jre ${WRKSRC}/LICENSE ${WRKSRC}/CHANGES \
				${WRKSRC}/COPYRIGHT ${WRKSRC}/README ${WRKSRC}/INSTALL

.include "../../lang/blackdown-jre13/Makefile.common"
.include "../../mk/bsd.pkg.mk"
