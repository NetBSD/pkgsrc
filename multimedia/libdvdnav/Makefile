# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:02 tv Exp $
#

DISTNAME=	libdvdnav-0.1.9
PKGREVISION=	1
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
