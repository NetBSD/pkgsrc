# $NetBSD: Makefile,v 1.9 2004/10/03 00:13:23 tv Exp $
#

DISTNAME=		pxtools-0.0.20
PKGREVISION=	1
CATEGORIES=		databases
MASTER_SITES=		http://jan.kneschke.de/projects/pxtools/download/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://jan.kneschke.de/projects/pxtools/
COMMENT=		Paradox database export/info utilities

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
