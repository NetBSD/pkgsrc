# $NetBSD: Makefile,v 1.12 2002/10/12 21:19:58 jschauma Exp $
#

BASENAME=	j2sdk
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jdk13-1
PKGREVISION=	1

COMMENT=	Linux port of the Blackdown Java(tm) Runtime Environment

DEPENDS=	blackdown-jre13>=1:../../lang/blackdown-jre13

.if ${MACHINE_ARCH} == "powerpc"
DISTNAME:=	${DISTNAME}.bin
.endif

# these are part of JRE
do-configure:
	@${RM} -r ${WRKSRC}/jre ${WRKSRC}/LICENSE ${WRKSRC}/CHANGES \
		${WRKSRC}/COPYRIGHT ${WRKSRC}/README ${WRKSRC}/INSTALL

.include "../../lang/blackdown-jre13/Makefile.common"
.include "../../mk/bsd.pkg.mk"
