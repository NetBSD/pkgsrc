# $NetBSD: Makefile,v 1.13 2025/04/21 21:23:07 wiz Exp $

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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CFLAGS.NetBSD=	-D_KMEMUSER

CFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
