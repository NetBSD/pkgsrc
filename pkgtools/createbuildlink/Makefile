# $NetBSD: Makefile,v 1.18 2003/09/18 14:15:00 jmmv Exp $
#

DISTNAME=	createbuildlink-2.7
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	rh@NetBSD.org
COMMENT=	Shell script to help creating a buildlink2.mk file

EXTRACT_ONLY=	# empty
USE_BUILDLINK2=	yes
NO_CHECKSUM=	yes
NO_BUILD=	yes
EXTRACT_CMD=	${ECHO}

SCRIPT=		${DISTNAME:C/-.*$//}

do-configure:
.for scr in ${SCRIPT}
	${SED}	-e 's/@PKGVERSION@/${PKGVERSION}/'		\
		-e 's/@MAKE@/${MAKE}/'				\
		< ${FILESDIR}/${scr} > ${WRKSRC}/${scr}
.endfor

do-install:
.for scr in ${SCRIPT}
	${INSTALL_SCRIPT} ${WRKSRC}/${scr} ${PREFIX}/bin/${scr}
.endfor
	${INSTALL_MAN} ${FILESDIR}/${SCRIPT}.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
