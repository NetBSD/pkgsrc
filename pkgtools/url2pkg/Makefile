# $NetBSD: Makefile,v 1.11 2001/01/29 09:57:41 abs Exp $
#

DISTNAME=	url2pkg-1.14
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	hubertf@netbsd.org

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_BUILD=	yes
NO_PATCH=	yes
EXTRACT_CMD=	${ECHO_CMD}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${DISTNAME:C/-.*$//} ${LOCALBASE}/bin/${DISTNAME:C/-.*$//}
	${INSTALL_MAN} ${FILESDIR}/${DISTNAME:C/-.*$//}.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
