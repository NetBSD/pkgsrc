# $NetBSD: Makefile,v 1.56 2020/05/16 06:28:52 rillig Exp $

PKGNAME=	createbuildlink-3.18
CATEGORIES=	pkgtools sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Shell script to help creating buildlink3.mk files
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
NO_BUILD=	yes

SCRIPT=		${PKGNAME:C/-.*$//}
SCRIPTS=	${SCRIPT} substplistbasedirs
REPLACE_SH+=	${SCRIPTS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_FILES.vars=	${SCRIPT}
SUBST_VARS.vars=	PKGVERSION MAKE

do-extract:
	cd ${FILESDIR} && ${CP} ${SCRIPTS} ${WRKSRC}

do-install:
.for scr in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC:Q}/${scr:Q} ${DESTDIR}${PREFIX}/bin/${scr:Q}
.endfor
	${INSTALL_MAN} ${FILESDIR:Q}/${SCRIPT:Q}.8 ${DESTDIR}${PREFIX}/${PKGMANDIR:Q}/man8

.include "../../mk/bsd.pkg.mk"
