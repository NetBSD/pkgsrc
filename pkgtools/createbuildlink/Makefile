# $NetBSD: Makefile,v 1.3.2.1 2002/06/23 18:57:40 jlam Exp $
#

DISTNAME=	createbuildlink-1.5
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

do-configure:
	${SED} -e 's/@PKGVERSION@/${PKGVERSION}/'		\
		< ${FILESDIR}/${DISTNAME:C/-.*$//}		\
		> ${WRKSRC}/${DISTNAME:C/-.*$//}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME:C/-.*$//}	\
		${PREFIX}/bin/${DISTNAME:C/-.*$//}
	${INSTALL_MAN} ${FILESDIR}/${DISTNAME:C/-.*$//}.8	\
		${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
