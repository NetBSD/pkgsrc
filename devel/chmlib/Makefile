# $NetBSD: Makefile,v 1.1.1.1 2004/01/06 15:34:01 wiz Exp $
#

DISTNAME=	chmlib-0.31
CATEGORIES=	devel
MASTER_SITES=	http://66.93.236.84/%7Ejedwin/projects/chmlib/
EXTRACT_SUFX=	.tbz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://66.93.236.84/%7Ejedwin/projects/chmlib/
COMMENT=	Library for dealing with Microsoft ITSS/CHM format files

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

PTHREAD_OPTS=		require

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
