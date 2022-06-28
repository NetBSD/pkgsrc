# $NetBSD: Makefile,v 1.19 2022/06/28 11:36:10 wiz Exp $

DISTNAME=	halibut-1.2
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/halibut/halibut-${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~sgtatham/halibut/
COMMENT=	Documentation production system
LICENSE=	mit

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gmake perl

BUILD_DIRS+=	. doc

MAKE_FLAGS+=	RELEASE=1
MAKE_FLAGS+=	VERSION=${PKGVERSION}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/halibut \
		${DESTDIR}${PREFIX}/bin/halibut
	${INSTALL_MAN} ${WRKSRC}/doc/halibut.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/halibut.1

.include "../../mk/bsd.pkg.mk"
