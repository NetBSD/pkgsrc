# $NetBSD: Makefile,v 1.31 2004/09/26 23:48:09 rh Exp $

DISTNAME=	createbuildlink-3.6
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	rh@NetBSD.org
COMMENT=	shell script to help creating buildlink3.mk files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
USE_LANGUAGES=	# empty
NO_CHECKSUM=	yes
NO_BUILDLINK=	yes
NO_BUILD=	yes
EXTRACT_CMD=	${ECHO}

SCRIPT=		${DISTNAME:C/-.*$//}
SCRIPTS=	${SCRIPT} substplistbasedirs

INSTALLATION_DIRS=	bin man/man8

do-configure:
.for scr in ${SCRIPTS}
	${SED}	-e 's|@PKGVERSION@|${PKGVERSION}|'		\
		-e 's|@MAKE@|${MAKE}|'				\
		< ${FILESDIR}/${scr} > ${WRKSRC}/${scr}
.endfor

do-install:
.for scr in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${scr} ${PREFIX}/bin/${scr}
.endfor
	${INSTALL_MAN} ${FILESDIR}/${SCRIPT}.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
