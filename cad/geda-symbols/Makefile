# $NetBSD: Makefile,v 1.16 2005/01/11 03:16:23 dmcmahill Exp $
#

DISTNAME=	geda-symbols-${PKGVERSION}
CATEGORIES=	cad

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Library of symbols for gEDA

CONFLICTS+=	gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make sed

.include "../../mk/bsd.pkg.mk"
