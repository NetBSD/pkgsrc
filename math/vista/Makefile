# $NetBSD: Makefile,v 1.19 2012/09/11 23:04:35 asau Exp $
#

DISTNAME=	vista
PKGNAME=	vista-5.05
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://forrest.psych.unc.edu/research/vista-frames/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://forrest.psych.unc.edu/research/
COMMENT=	Visual statistics system

DEPENDS+=	xlispstat>=3.52.9:../../math/xlispstat

MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/vista-5.0.5
USE_X11BASE=	yes
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
