# $NetBSD: Makefile,v 1.45 2003/09/16 14:36:08 abs Exp $

DISTNAME=	pkgchk-1.41
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Check installed package versions against pkgsrc

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES

.include "../../mk/bsd.prefs.mk"

MAKECONF?=	/etc/mk.conf

do-build:
	${SED} -e 's#@MAKE@#${MAKE}#g' \
	  -e 's#@MAKECONF@#${MAKECONF}#g' \
	  ${FILESDIR}/pkgchk.sh >${WRKSRC}/pkgchk.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgchk.sh ${PREFIX}/sbin/pkg_chk
	${INSTALL_MAN} ${FILESDIR}/pkgchk.8 ${PREFIX}/man/man8/pkg_chk.8

.include "../../mk/bsd.pkg.mk"
