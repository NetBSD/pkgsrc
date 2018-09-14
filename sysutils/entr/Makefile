# $NetBSD: Makefile,v 1.10 2018/09/14 02:08:28 schmonz Exp $
#

DISTNAME=	entr-4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://entrproject.org/code/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://entrproject.org/
COMMENT=	Run arbitrary commands when files change
LICENSE=	isc AND 2-clause-bsd

WRKSRC=		${WRKDIR}/eradman-entr-f4e2cbe57708

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
