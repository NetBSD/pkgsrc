# $NetBSD: Makefile,v 1.12 2020/02/14 18:51:39 leot Exp $
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

.include "../../mk/bsd.pkg.mk"
