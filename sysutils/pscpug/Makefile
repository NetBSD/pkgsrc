# $NetBSD: Makefile,v 1.9 2017/01/03 22:38:01 roy Exp $

DISTNAME=		pscpug035
PKGNAME=		pscpug-0.3.5
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.diablonet.net/~mercadal/projects/pscpug/
EXTRACT_SUFX=		.tgz

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.diablonet.net/~mercadal/projects/pscpug/
COMMENT=		Graph a given process's CPU usage

GNU_CONFIGURE=		yes

NOT_FOR_PLATFORM=	Interix-*-* # no rusage or procfs stats

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CFLAGS.NetBSD=	-D_KMEMUSER

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
