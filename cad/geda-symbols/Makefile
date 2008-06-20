# $NetBSD: Makefile,v 1.21 2008/06/20 01:09:08 joerg Exp $
#

DISTNAME=	geda-symbols-${PKGVERSION}
CATEGORIES=	cad

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Library of symbols for gEDA

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake gsed

post-install:
	${RM} -f ${PREFIX}/share/gEDA/sym/micro/gschem.log.old

.include "../../mk/bsd.pkg.mk"
