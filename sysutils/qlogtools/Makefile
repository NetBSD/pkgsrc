# $NetBSD: Makefile,v 1.3 2003/07/21 17:24:24 martti Exp $
#

DISTNAME=	qlogtools-3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://untroubled.org/qlogtools/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://untroubled.org/qlogtools/
COMMENT=	Set of tools useful in analyzing logs from qmail and other pkgs

pre-build:
	${ECHO} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	${ECHO} ${PREFIX}/man > ${WRKSRC}/conf-man

do-install:
	cd ${WRKSRC} && ./installer

.include "../../mk/bsd.pkg.mk"
