# $NetBSD: Makefile,v 1.7 2004/03/30 18:36:27 ben Exp $
#

DISTNAME=		pxtools-0.0.20
CATEGORIES=		databases
MASTER_SITES=		http://jan.kneschke.de/projects/pxtools/download/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://jan.kneschke.de/projects/pxtools/
COMMENT=		Paradox database export/info utilities

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
