# $NetBSD: Makefile,v 1.6 2016/12/17 12:32:15 leot Exp $
#

DISTNAME=	entr-3.6
CATEGORIES=	sysutils
MASTER_SITES=	http://entrproject.org/code/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://entrproject.org/
COMMENT=	Run arbitrary commands when files change
LICENSE=	isc AND 2-clause-bsd

WRKSRC=		${WRKDIR}/eradman-entr-c15b0be493fc

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
