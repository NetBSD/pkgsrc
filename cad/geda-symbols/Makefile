# $NetBSD: Makefile,v 1.17 2005/05/22 20:07:41 jlam Exp $
#

DISTNAME=	geda-symbols-${PKGVERSION}
CATEGORIES=	cad

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Library of symbols for gEDA

CONFLICTS+=	gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake gsed

.include "../../mk/bsd.pkg.mk"
