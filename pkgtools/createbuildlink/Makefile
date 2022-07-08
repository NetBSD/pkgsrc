# $NetBSD: Makefile,v 1.57 2022/07/08 18:06:19 rillig Exp $

PKGNAME=	createbuildlink-3.19
CATEGORIES=	pkgtools sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Shell script to help creating buildlink3.mk files
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes

SCRIPT=		createbuildlink
SCRIPTS=	${SCRIPT} substplistbasedirs
REPLACE_SH+=	${SCRIPTS}

AUTO_MKDIRS=	yes

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_FILES.vars=	${SCRIPT}
SUBST_VARS.vars=	PKGVERSION MAKE

do-extract:
	cd ${FILESDIR} && ${CP} ${SCRIPTS} ${WRKSRC}

do-install:
.for scr in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${scr} ${DESTDIR}${PREFIX}/bin/
.endfor
	${INSTALL_MAN} ${FILESDIR}/${SCRIPT}.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
