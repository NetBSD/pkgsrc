# $NetBSD: Makefile,v 1.26 2003/04/23 09:18:29 rh Exp $
#

DISTNAME=	url2pkg-1.23
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Tool to automate initial steps in building a package

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes
EXTRACT_CMD=	${ECHO}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${DISTNAME:C/-.*$//} ${PREFIX}/bin/${DISTNAME:C/-.*$//}
	${INSTALL_MAN} ${FILESDIR}/${DISTNAME:C/-.*$//}.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
