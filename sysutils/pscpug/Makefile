# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:46 joerg Exp $
#

DISTNAME=		pscpug032
PKGNAME=		pscpug-0.3.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.diablonet.net/~mercadal/projects/pscpug/
EXTRACT_SUFX=		.tgz

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://www.diablonet.net/~mercadal/projects/pscpug/
COMMENT=		Graph a given process's CPU usage

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

NOT_FOR_PLATFORM=	Interix-*-* # no rusage or procfs stats

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
