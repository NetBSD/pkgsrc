# $NetBSD: Makefile,v 1.13 2020/05/23 10:26:54 rillig Exp $
#

DISTNAME=	entr-4.4
CATEGORIES=	sysutils
MASTER_SITES=	http://eradman.com/entrproject/code/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://eradman.com/entrproject/
COMMENT=	Run arbitrary commands when files change
LICENSE=	isc AND 2-clause-bsd

MAKE_ENV+=	MANPREFIX="${PREFIX}/${PKGMANDIR}"

.include "../../mk/bsd.prefs.mk"

# Needs kqueue(2) or inotify(7)
.if !empty(OPSYS:M*BSD) || ${OPSYS} == "Bitrig" || ${OPSYS} == "DragonFly"
MAKE_FILE=		Makefile.bsd
.elif ${OPSYS} == "Darwin"
MAKE_FILE=		Makefile.macos
.elif ${OPSYS} == "Linux"
MAKE_FILE=		Makefile.linux
.else
NOT_FOR_PLATFORM=	${MACHINE_PLATFORM}
.endif

TEST_TARGET=	test
USE_TOOLS+=	bash:test
.if ${PKGSRC_RUN_TEST:tl} == yes
REPLACE_BASH+=	system_test.sh
.endif

.include "../../mk/bsd.pkg.mk"
