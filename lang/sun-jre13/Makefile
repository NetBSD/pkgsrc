# $NetBSD: Makefile,v 1.23 2002/08/29 14:07:30 wiz Exp $

# MASTER_SITES is very special, and must end in "=":
DISTNAME=	j2re-1_3_1_02-linux-i386
PKGNAME=	sun-jre13-1.0.2
PKGREVISION=	1
MASTER_SITES=	http://java.sun.com/Download4?config-file=j2re-1_3_1_02.config&platform=linux-i386&protocol=HTTP+download&download-name=

COMMENT=	Sun's Java(tm) Runtime Environment 1.3.1

WRKSRC=		${WRKDIR}/jre1.3.1_02
NO_CONFIGURE=	# defined

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

.include "../../lang/sun-jre13/Makefile.common"
