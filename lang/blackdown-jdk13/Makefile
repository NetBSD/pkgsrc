# $NetBSD: Makefile,v 1.13 2002/10/13 07:41:57 jlam Exp $
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
post-extract:
	${RM} -fr ${WRKSRC}/jre
	${RM} -f ${WRKSRC}/LICENSE ${WRKSRC}/CHANGES			\
		${WRKSRC}/COPYRIGHT ${WRKSRC}/README ${WRKSRC}/INSTALL	\
		${WRKSRC}/bin/.java_wrapper

.include "../../lang/blackdown-jre13/Makefile.common"

PREFIX=		${JVM_HOME}
