# $NetBSD: Makefile,v 1.1.1.1 2004/04/06 13:44:52 jmmv Exp $
#

DISTNAME=	libdvdnav-0.1.9
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvd/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dvd.sourceforge.net/
COMMENT=	Library to navigate DVDs

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
