# $NetBSD: Makefile,v 1.8 2004/04/17 19:21:09 snj Exp $
#

DISTNAME=		pxtools-0.0.20
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
