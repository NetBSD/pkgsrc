# $NetBSD: Makefile,v 1.4 2016/06/05 13:50:21 mef Exp $
#

DISTNAME=	entr-3.5
CATEGORIES=	sysutils
MASTER_SITES=	http://entrproject.org/code/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://entrproject.org/
COMMENT=	Run arbitrary commands when files change
LICENSE=	isc AND 2-clause-bsd

WRKSRC=		${WRKDIR}/eradman-entr-697748046070

.include "../../mk/bsd.prefs.mk"

# Needs kqueue(2) or inotify(7)
.if !empty(OPSYS:M*BSD) || ${OPSYS} == "Bitrig" || ${OPSYS} == "DragonFly"
MAKE_FILE=	Makefile.bsd
.elif ${OPSYS} == "Darwin"
MAKE_FILE=	Makefile.macos
.elif ${OPSYS} == "Linux"
MAKE_FILE=	Makefile.linux
.else
NOT_FOR_PLATFORM=	${MACHINE_PLATFORM}
.endif

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
