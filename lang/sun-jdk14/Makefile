# $NetBSD: Makefile,v 1.2 2002/07/27 22:21:04 jschauma Exp $

# MASTER_SITES is very special, and must end in "=":
DISTNAME=	j2sdk-1_4_0-linux-i386
PKGNAME=	sun-jdk14-0
PKGREVISION=	1
MASTER_SITES=	http://java.sun.com/Download4?config-file=j2sdk-1_4_0.config&platform=linux-i386&protocol=HTTP+download&download-name=

COMMENT=	Sun's Java(tm) Development Kit 1.4.0

DEPENDS=	sun-jre14>=0:../../lang/sun-jre14

WRKSRC=		${WRKDIR}/j2sdk1.4.0

# these are part of JRE
do-configure:
	${RM} -fr ${WRKSRC}/jre ${WRKSRC}/LICENSE ${WRKSRC}/README

.include "../../lang/sun-jre14/Makefile.common"
.include "../../mk/bsd.pkg.mk"

# These need to be after bsd.pkg.mk 
PREFIX:=	${JDK_HOME}
