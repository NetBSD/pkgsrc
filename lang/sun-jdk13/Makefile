# $NetBSD: Makefile,v 1.15 2002/07/27 22:01:33 jschauma Exp $

# MASTER_SITES is very special, and must end in "=":
DISTNAME=	j2sdk-1_3_1_02-linux-i386
PKGNAME=	sun-jdk13-1.0.2
PKGREVISION=	1
MASTER_SITES=	http://java.sun.com/Download4?config-file=j2sdk-1_3_1_02.config&platform=linux-i386&protocol=HTTP+download&download-name=

COMMENT=	Sun's Java(tm) Development Kit 1.3.1

DEPENDS=	sun-jre13>=1:../../lang/sun-jre13

WRKSRC=		${WRKDIR}/jdk1.3.1_02

# these are part of JRE
do-configure:
	@${RM} -fr ${WRKSRC}/jre ${WRKSRC}/LICENSE ${WRKSRC}/README ${WRKSRC}/bin/.java_wrapper

.include "../../lang/sun-jre13/Makefile.common"
