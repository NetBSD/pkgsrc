# $NetBSD: Makefile,v 1.1 2016/05/02 02:29:14 seb Exp $

DISTNAME=		bats-0.4.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=sstephenson/}

MAINTAINER=		pkgsrc@NetBSD.org
HOMEPAGE=		https://github.com/sstephenson/bats
COMMENT=		Testing framework for Bash
LICENSE=		mit

GITHUB_TAG=		v${PKGVERSION_NOREV}

USE_LANGUAGES=		# none

NO_BUILD=		yes
USE_TOOLS+=		bash:run

CHECK_INTERPRETER_SKIP=	bin/bats libexec/bats*

do-install:
	cd ${WRKSRC} && ./install.sh ${DESTDIR}${PREFIX}

do-test:
	cd ${WRKSRC} && ./bin/bats ./test

.include "../../mk/bsd.pkg.mk"
