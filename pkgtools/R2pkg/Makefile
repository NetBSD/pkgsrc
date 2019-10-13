# $NetBSD: Makefile,v 1.7 2019/10/13 13:26:22 rillig Exp $
#

VERS=		0.6.2
PKGNAME=	R2pkg-${VERS}
CATEGORIES=	pkgtools

MAINTAINER=	brook@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Tool to automate initial steps in building an R package
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none
AUTO_MKDIRS=	yes

DEPENDS+=	curl>=7.52.1:../../www/curl

SUBST_CLASSES+=	R
SUBST_STAGE.R=	pre-configure
SUBST_FILES.R=	R2pkg.sh
SUBST_VARS.R=	VERS MAKE LIBDIR
LIBDIR=		${PREFIX}/lib/R2pkg

do-extract:
	cd ${FILESDIR} && ${CP} R2pkg.* ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/R2pkg.sh ${DESTDIR}${PREFIX}/sbin/R2pkg
	${INSTALL_DATA} ${WRKSRC}/R2pkg.R ${DESTDIR}${LIBDIR}/R2pkg.R
	${INSTALL_MAN} ${WRKSRC}/R2pkg.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/R2pkg.8

.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
