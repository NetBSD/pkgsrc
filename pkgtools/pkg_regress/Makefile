# $NetBSD: Makefile,v 1.2 2004/10/07 02:01:38 jlam Exp $

DISTNAME=	pkg_regress-0.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gavan@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Run pkgsrc infrastructure regression test suite

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
USE_LANGUAGES=	# empty
NO_CHECKSUM=	YES

INSTALLATION_DIRS=	sbin

.include "../../mk/bsd.prefs.mk"

do-build:
	${SED} -e 's#@MAKE@#${MAKE}#g' \
	  -e 's#@PKGSRCDIR@#${PKGSRCDIR}#g' \
	  -e 's#@SH@#${SH}#g' \
	  -e 's#@EGREP@#${EGREP}#g' \
	  ${FILESDIR}/pkg_regress.sh >${WRKSRC}/pkg_regress.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_regress.sh ${PREFIX}/sbin/pkg_regress

.include "../../mk/bsd.pkg.mk"
