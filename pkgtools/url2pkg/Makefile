# $NetBSD: Makefile,v 1.7 2000/06/22 00:03:36 hubertf Exp $
#

DISTNAME=	url2pkg-1.11
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

.include "../../mk/bsd.pkg.mk"
