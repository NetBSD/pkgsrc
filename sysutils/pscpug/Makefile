# $NetBSD: Makefile,v 1.2 2007/02/08 15:54:15 tv Exp $
#

DISTNAME=		pscpug032
PKGNAME=		pscpug-0.3.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.diablonet.net/~mercadal/projects/pscpug/
EXTRACT_SUFX=		.tgz

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://www.diablonet.net/~mercadal/projects/pscpug/
COMMENT=		Graph a given process's CPU usage

GNU_CONFIGURE=		yes

NOT_FOR_PLATFORM=	Interix-*-* # no rusage or procfs stats

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
