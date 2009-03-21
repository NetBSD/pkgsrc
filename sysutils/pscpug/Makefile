# $NetBSD: Makefile,v 1.4 2009/03/21 17:35:06 snj Exp $

DISTNAME=		pscpug035
PKGNAME=		pscpug-0.3.5
CATEGORIES=		sysutils
MASTER_SITES=		http://www.diablonet.net/~mercadal/projects/pscpug/
EXTRACT_SUFX=		.tgz

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.diablonet.net/~mercadal/projects/pscpug/
COMMENT=		Graph a given process's CPU usage

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

NOT_FOR_PLATFORM=	Interix-*-* # no rusage or procfs stats

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
