# $NetBSD: Makefile,v 1.1.1.1 2004/01/10 17:05:44 cjep Exp $
# FreeBSD Id: ports/shells/nologinmsg/Makefile,v 1.3 2003/02/21 13:26:58 knu Exp

DISTNAME=	nologinmsg-1.0
CATEGORIES=	shells sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	cjep@NetBSD.org
#HOMEPAGE=
COMMENT=	More functional native binary replacement for /sbin/nologin

USE_BUILDLINK2=	yes

post-patch:
	${MV} ${WRKSRC}/nologinmsg.8 ${WRKSRC}/nologinmsg.8.1
	${SED} -e 's|/usr/local/etc|${PKG_SYSCONFDIR}|g' 	\
			${WRKSRC}/nologinmsg.8.1 > ${WRKSRC}/nologinmsg.8
	${MV} ${WRKSRC}/pathnames.h ${WRKSRC}/pathnames.h.1
	${SED} -e 's|/usr/local/etc|${PKG_SYSCONFDIR}|g' 	\
			${WRKSRC}/pathnames.h.1 > ${WRKSRC}/pathnames.h

.include "../../mk/bsd.pkg.mk"
