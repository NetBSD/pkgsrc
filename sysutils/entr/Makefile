# $NetBSD: Makefile,v 1.28 2024/11/21 15:43:04 leot Exp $

DISTNAME=	entr-5.6
CATEGORIES=	sysutils
MASTER_SITES=	https://eradman.com/entrproject/code/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://eradman.com/entrproject/
COMMENT=	Run arbitrary commands when files change
LICENSE=	isc AND 2-clause-bsd

MAKE_ENV+=	MANPREFIX="${PREFIX}/${PKGMANDIR}"

.include "../../mk/bsd.prefs.mk"

HAS_CONFIGURE=	yes

TEST_TARGET=	test
USE_TOOLS+=	bash:test
CHECK_PORTABILITY_SKIP+=	system_test.sh
.if ${PKGSRC_RUN_TEST:tl} == yes
REPLACE_BASH+=	system_test.sh
.endif

.include "../../mk/bsd.pkg.mk"
