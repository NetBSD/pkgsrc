# $NetBSD: Makefile,v 1.4 2000/12/07 13:15:43 wiz Exp $
#

DISTNAME=	vista
PKGNAME=	vista-5.05
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://forrest.psych.unc.edu/research/vista.html

DEPENDS+=	xlispstat>=3.52.9:../../math/xlispstat

WRKSRC=		${WRKDIR}/vista-5.0.5
USE_X11BASE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
