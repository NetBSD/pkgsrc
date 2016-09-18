# $NetBSD: Makefile,v 1.3 2016/09/18 05:31:38 dholland Exp $

DISTNAME=		bats-0.4.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=sstephenson/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/sstephenson/bats
COMMENT=		Testing framework for Bash
LICENSE=		mit

GITHUB_TAG=		v${PKGVERSION_NOREV}

USE_LANGUAGES=		# none

NO_BUILD=		yes
USE_TOOLS+=		bash:run

CHECK_INTERPRETER_SKIP=	bin/bats libexec/bats*

do-install:
	cd ${WRKSRC} && ${SETENV} PKGMANDIR=${PKGMANDIR} ./install.sh ${DESTDIR}${PREFIX}

do-test:
	cd ${WRKSRC} && ./bin/bats ./test

.include "../../mk/bsd.pkg.mk"
