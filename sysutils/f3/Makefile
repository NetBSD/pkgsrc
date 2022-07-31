# $NetBSD: Makefile,v 1.1 2022/07/31 12:29:10 wiz Exp $

DISTNAME=	f3-1.1.3.20110921
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=kcarnold/}
GITHUB_TAG=	625b0f2ea7fb3bacc04f555f48dc38b498ad0b2e

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kcarnold/f3
COMMENT=	Flash memory tester
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o f3read f3read.c && \
	${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o f3write f3write.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/f3read ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/f3write ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
