# $NetBSD: Makefile,v 1.21 2002/12/12 14:40:07 abs Exp $
#

DISTNAME=	url2pkg-1.20
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Tool to automate initial steps in building a package

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_BUILD=	yes
NO_PATCH=	yes
EXTRACT_CMD=	${ECHO}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${DISTNAME:C/-.*$//} ${PREFIX}/bin/${DISTNAME:C/-.*$//}
	${INSTALL_MAN} ${FILESDIR}/${DISTNAME:C/-.*$//}.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
