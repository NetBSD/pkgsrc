# $NetBSD: Makefile,v 1.2 2023/02/14 15:08:42 schmonz Exp $

DISTNAME=	shunit2-2.1.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kward/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kward/shunit2
COMMENT=	Unit test framework for Bourne based shell scripts
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/shunit2 ${DESTDIR}${PREFIX}/bin/shunit2

.include "../../mk/bsd.pkg.mk"
