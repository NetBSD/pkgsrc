# $NetBSD: Makefile,v 1.1.1.1 2001/08/13 14:53:02 zuntum Exp $
#

DISTNAME=	qlogtools-3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://untroubled.org/qlogtools/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://untroubled.org/qlogtools/
COMMENT=	set of tools useful in analyzing logs from qmail and other pkgs

pre-build:
	${ECHO} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	${ECHO} ${PREFIX}/man > ${WRKSRC}/conf-man

do-install:
	cd ${WRKSRC} && ./installer

.include "../../mk/bsd.pkg.mk"
