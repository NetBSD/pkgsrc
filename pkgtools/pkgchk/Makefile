# $NetBSD: Makefile,v 1.29 2002/04/01 20:20:05 abs Exp $

DISTNAME=	pkgchk-1.28
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Check installed package versions against pkgsrc

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
WRKSRC=		${WRKDIR}

do-build:
	${SED} -e 's#@MAKE@#${MAKE}#g' ${FILESDIR}/pkgchk.sh \
	  >${WRKSRC}/pkgchk.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgchk.sh ${PREFIX}/sbin/pkg_chk
	${INSTALL_MAN} ${FILESDIR}/pkgchk.8 ${PREFIX}/man/man8/pkg_chk.8

.include "../../mk/bsd.pkg.mk"
