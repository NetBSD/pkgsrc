# $NetBSD: Makefile,v 1.5 2019/08/08 20:14:26 brook Exp $
#

VERS=		0.6
PKGNAME=	R2pkg-${VERS}
CATEGORIES=	pkgtools

MAINTAINER=	brook@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Tool to automate initial steps in building an R package
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
USE_LANGUAGES=		# none
AUTO_MKDIRS=		yes

DEPENDS+=		curl>=7.52.1:../../www/curl

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_MESSAGE.version=	Substituting version in R2pkg.sh.
SUBST_FILES.version=	R2pkg.sh
SUBST_VARS.version=	VERS

SUBST_CLASSES+=		tools
SUBST_STAGE.tools=	pre-configure
SUBST_MESSAGE.tools=	Substituting tool locations.
SUBST_FILES.tools=	R2pkg.sh
SUBST_VARS.tools=	MAKE

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man8

do-extract:
	${CP} ${FILESDIR}/R2pkg.sh ${WRKSRC}
	${CP} ${FILESDIR}/R2pkg.8 ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/R2pkg.sh ${DESTDIR}${PREFIX}/sbin/R2pkg
	${INSTALL_MAN} ${WRKSRC}/R2pkg.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/R2pkg.8

.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
