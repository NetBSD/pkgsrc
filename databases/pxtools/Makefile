# $NetBSD: Makefile,v 1.15 2011/04/22 13:43:14 obache Exp $
#

DISTNAME=		pxtools-0.0.20
PKGREVISION=	3
CATEGORIES=		databases
MASTER_SITES=		http://jan.kneschke.de/projects/pxtools/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jan.kneschke.de/projects/pxtools/
COMMENT=		Paradox database export/info utilities

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake

GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
