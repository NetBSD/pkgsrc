# $NetBSD: Makefile,v 1.2 2004/10/03 00:17:52 tv Exp $
#

DISTNAME=	giFT-FastTrack-0.8.6
PKGNAME=	${DISTNAME:S/giFT-FastTrack/gift-fasttrack/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/gift-fasttrack/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://download.berlios.de/gift-fasttrack/
COMMENT=	Fasttrack plugin for giFT

WRKSRC=			${WRKDIR}/giFT-FastTrack-0.8.6
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../net/gift/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
