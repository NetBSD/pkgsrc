# $NetBSD: Makefile,v 1.1 2017/07/04 10:06:56 jperkin Exp $

DISTNAME=	shunit2-2.1.6
CATEGORIES=	devel
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/shunit2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kward/shunit2
COMMENT=	Unit test framework for Bourne based shell scripts
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/shunit2 ${DESTDIR}${PREFIX}/bin/shunit2

.include "../../mk/bsd.pkg.mk"
