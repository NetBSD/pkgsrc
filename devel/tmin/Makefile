# $NetBSD: Makefile,v 1.2 2014/12/10 20:07:45 wiz Exp $

DISTNAME=	tmin-0.05
CATEGORIES=	devel
MASTER_SITES=	https://tmin.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/tmin/
COMMENT=	Tool for minimizing complex test cases in security testing
LICENSE=	apache-2.0

WRKSRC=	${WRKDIR}/tmin

INSTALLATION_DIRS=	bin share/doc/tmin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tmin ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/tmin

.include "../../mk/bsd.pkg.mk"
