# $NetBSD: Makefile,v 1.3 2004/04/08 18:48:53 abs Exp $

DISTNAME=	pkg_chk-1.46
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Check installed package versions against pkgsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
USE_LANGUAGES=	# empty
NO_CHECKSUM=	YES

CONFLICTS=	pkgchk-[0-9]*

INSTALLATION_DIRS=	sbin man/man8

.include "../../mk/bsd.prefs.mk"

MAKECONF?=	/etc/mk.conf

do-build:
	${SED} -e 's#@MAKE@#${MAKE}#g' \
	  -e 's#@MAKECONF@#${MAKECONF}#g' \
	  ${FILESDIR}/pkg_chk.sh >${WRKSRC}/pkg_chk.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_chk.sh ${PREFIX}/sbin/pkg_chk
	${INSTALL_MAN} ${FILESDIR}/pkg_chk.8 ${PREFIX}/man/man8/pkg_chk.8

.include "../../mk/bsd.pkg.mk"
