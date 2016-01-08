# $NetBSD: Makefile,v 1.2 2016/01/08 20:19:12 leot Exp $
#

DISTNAME=	entr-3.4
CATEGORIES=	sysutils
MASTER_SITES=	http://entrproject.org/code/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://entrproject.org/code/
COMMENT=	Run arbitrary commands when files change
LICENSE=	isc AND 2-clause-bsd

WRKSRC=		${WRKDIR}/eradman-entr-5321b01c9dab

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
