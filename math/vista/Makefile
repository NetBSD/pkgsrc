# $NetBSD: Makefile,v 1.7 2003/06/02 01:18:20 jschauma Exp $
#

DISTNAME=	vista
PKGNAME=	vista-5.05
WRKSRC=		${WRKDIR}/vista-5.0.5
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://forrest.psych.unc.edu/research/vista.html
COMMENT=	Visual statistics system

DEPENDS+=	xlispstat>=3.52.9:../../math/xlispstat

USE_X11BASE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
