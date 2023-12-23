# $NetBSD: Makefile,v 1.11 2023/12/23 09:19:39 zafer Exp $

DISTNAME=		pscpug035
PKGNAME=		pscpug-0.3.5
PKGREVISION=		3
CATEGORIES=		sysutils
MASTER_SITES=		https://www.aydogan.net/distfiles/sysutils/
EXTRACT_SUFX=		.tgz

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.diablonet.net/~mercadal/projects/pscpug/
COMMENT=		Graph a given process's CPU usage
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes

NOT_FOR_PLATFORM=	Interix-*-* # no rusage or procfs stats

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CFLAGS.NetBSD=	-D_KMEMUSER

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
