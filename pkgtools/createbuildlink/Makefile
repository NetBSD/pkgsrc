# $NetBSD: Makefile,v 1.42 2006/07/12 13:29:03 wiz Exp $

DISTNAME=	createbuildlink-3.13
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	rh@NetBSD.org
COMMENT=	Shell script to help creating buildlink3.mk files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
USE_LANGUAGES=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes

SCRIPT=		${DISTNAME:C/-.*$//}
SCRIPTS=	${SCRIPT} substplistbasedirs

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-configure:
.for scr in ${SCRIPTS}
	${SED}	-e 's|@PKGVERSION@|${PKGVERSION}|'		\
		-e 's|@MAKE@|${MAKE}|'				\
		< ${FILESDIR:Q}/${scr:Q} > ${WRKSRC:Q}/${scr:Q}
.endfor

do-install:
.for scr in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC:Q}/${scr:Q} ${PREFIX:Q}/bin/${scr:Q}
.endfor
	${INSTALL_MAN} ${FILESDIR:Q}/${SCRIPT:Q}.8 ${PREFIX:Q}/${PKGMANDIR:Q}/man8

.include "../../mk/bsd.pkg.mk"
