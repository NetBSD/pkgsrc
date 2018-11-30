# $NetBSD: Makefile,v 1.16 2018/11/30 19:07:37 rillig Exp $

PKGNAME=	pkg_regress-0.4
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Run pkgsrc infrastructure regression test suite

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes
AUTO_MKDIRS=	yes

SUBST_CLASSES+=		regress
SUBST_STAGE.regress=	pre-configure
SUBST_FILES.regress=	pkg_regress.sh
SUBST_VARS.regress=	MAKE PKGSRCDIR SH EGREP

do-extract:
	${CP} ${FILESDIR}/pkg_regress.sh ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_regress.sh \
		${DESTDIR}${PREFIX}/sbin/pkg_regress

.include "../../mk/bsd.pkg.mk"
