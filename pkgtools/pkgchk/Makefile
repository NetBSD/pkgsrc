# $NetBSD: Makefile,v 1.29.2.1 2002/06/23 18:57:44 jlam Exp $

DISTNAME=	pkgchk-1.30
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Check installed package versions against pkgsrc

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
WRKSRC=		${WRKDIR}

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
