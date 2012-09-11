# $NetBSD: Makefile,v 1.49 2012/09/11 23:19:34 asau Exp $

DISTNAME=	createbuildlink-3.16
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	rh@NetBSD.org
COMMENT=	Shell script to help creating buildlink3.mk files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
NO_BUILD=	yes

SCRIPT=		${DISTNAME:C/-.*$//}
SCRIPTS=	${SCRIPT} substplistbasedirs
REPLACE_SH+=	${SCRIPTS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-extract:
.for scr in ${SCRIPTS}
	${SED}	-e 's|@PKGVERSION@|${PKGVERSION}|'		\
		-e 's|@MAKE@|${MAKE}|'				\
		< ${FILESDIR:Q}/${scr:Q} > ${WRKSRC:Q}/${scr:Q}
.endfor

do-install:
.for scr in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC:Q}/${scr:Q} ${DESTDIR}${PREFIX}/bin/${scr:Q}
.endfor
	${INSTALL_MAN} ${FILESDIR:Q}/${SCRIPT:Q}.8 ${DESTDIR}${PREFIX}/${PKGMANDIR:Q}/man8

.include "../../mk/bsd.pkg.mk"
