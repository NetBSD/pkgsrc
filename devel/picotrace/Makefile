# $NetBSD: Makefile,v 1.1 2019/05/06 23:18:10 kamil Exp $

GITHUB_PROJECT=	picotrace
GITHUB_TAG=	20190507
DISTNAME=	picotrace-${GITHUB_TAG}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=krytarowski/}

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://github.com/krytarowski/picotrace/
COMMENT=	System call process tracer
LICENSE=	2-clause-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-*

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		nroff

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
