# $NetBSD: Makefile,v 1.14 2008/06/12 02:14:20 joerg Exp $
#

DISTNAME=		pxtools-0.0.20
PKGREVISION=	2
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
