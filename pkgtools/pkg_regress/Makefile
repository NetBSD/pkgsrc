# $NetBSD: Makefile,v 1.14 2016/06/11 09:37:16 rillig Exp $

PKGNAME=	pkg_regress-0.3
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Run pkgsrc infrastructure regression test suite

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty

INSTALLATION_DIRS=	sbin

.include "../../mk/bsd.prefs.mk"

do-build:
	${SED} -e 's#@MAKE@#${MAKE}#g' \
	  -e 's#@PKGSRCDIR@#${PKGSRCDIR}#g' \
	  -e 's#@SH@#${SH}#g' \
	  -e 's#@EGREP@#${EGREP}#g' \
	  ${FILESDIR}/pkg_regress.sh >${WRKSRC}/pkg_regress.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_regress.sh \
		${DESTDIR}${PREFIX}/sbin/pkg_regress

.include "../../mk/bsd.pkg.mk"
