# $NetBSD: Makefile,v 1.2 2002/05/05 00:00:37 rh Exp $
#

DISTNAME=	createbuildlink-1.1
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	rh@netbsd.org
COMMENT=	Shell script to help creating a buildlink.mk file

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
