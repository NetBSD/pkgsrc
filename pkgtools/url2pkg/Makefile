# $NetBSD: Makefile,v 1.16 2001/10/31 18:45:42 zuntum Exp $
#

DISTNAME=	url2pkg-1.16
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Shellscript to help with the first steps to build a package

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
