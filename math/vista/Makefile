# $NetBSD: Makefile,v 1.10 2004/01/24 13:58:23 grant Exp $
#

DISTNAME=	vista
PKGNAME=	vista-5.05
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://forrest.psych.unc.edu/research/vista.html
COMMENT=	Visual statistics system

DEPENDS+=	xlispstat>=3.52.9:../../math/xlispstat

WRKSRC=		${WRKDIR}/vista-5.0.5
USE_X11BASE=	yes
USE_GNU_TOOLS+=	make

.include "../../mk/bsd.pkg.mk"
