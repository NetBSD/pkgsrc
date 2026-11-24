# $NetBSD: Makefile,v 1.14 2026/11/24 18:18:06 wiz Exp $

DISTNAME=		pscpug035
PKGNAME=		pscpug-0.3.5
PKGREVISION=		3
CATEGORIES=		sysutils
MASTER_SITES=		http://www.charlesmercadal.com/assets/software/
EXTRACT_SUFX=		.tgz

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.charlesmercadal.com/software/2019/06/24/pscpug.html
COMMENT=		Graph a given process's CPU usage
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CFLAGS.NetBSD=	-D_KMEMUSER

CFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
