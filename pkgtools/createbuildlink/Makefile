# $NetBSD: Makefile,v 1.23 2004/01/20 12:23:57 agc Exp $
#

DISTNAME=	createbuildlink-3.0
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	rh@NetBSD.org
COMMENT=	Shell script to help creating a buildlink2.mk file

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILDLINK=	yes
NO_BUILD=	yes
EXTRACT_CMD=	${ECHO}

SCRIPT=		${DISTNAME:C/-.*$//}

INSTALLATION_DIRS=	bin man/man8

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
