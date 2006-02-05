# $NetBSD: Makefile,v 1.19 2006/02/05 23:08:21 joerg Exp $
#

DISTNAME=	geda-symbols-${PKGVERSION}
PKGREVISION=	1
CATEGORIES=	cad

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Library of symbols for gEDA

CONFLICTS+=	gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake gsed

post-install:
	${RM} -f ${PREFIX}/share/gEDA/sym/micro/gschem.log.old

.include "../../mk/bsd.pkg.mk"
