# $NetBSD: Makefile,v 1.8 2002/09/23 01:39:50 jlam Exp $
#

DISTNAME=	createbuildlink-2.0
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	rh@netbsd.org
COMMENT=	Shell script to help creating a buildlink.mk file

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	yes
NO_CHECKSUM=	yes
NO_BUILD=	yes
NO_PATCH=	yes
EXTRACT_CMD=	${ECHO}

SCRIPT=		${DISTNAME:C/-.*$//}

do-configure:
.for scr in ${SCRIPT} ${SCRIPT}1
	${SED} -e 's/@PKGVERSION@/${PKGVERSION}/'		\
		< ${FILESDIR}/${scr} > ${WRKSRC}/${scr}
.endfor

do-install:
.for scr in ${SCRIPT} ${SCRIPT}1
	${INSTALL_SCRIPT} ${WRKSRC}/${scr} ${PREFIX}/bin/${scr}
.endfor
	${INSTALL_MAN} ${FILESDIR}/${SCRIPT}.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
