# $NetBSD: Makefile,v 1.4 2005/02/15 22:32:51 peter Exp $
#

DISTNAME=	giFT-FastTrack-0.8.9
PKGNAME=	${DISTNAME:S/giFT-FastTrack/gift-fasttrack/}
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/gift-fasttrack/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://download.berlios.de/gift-fasttrack/
COMMENT=	Fasttrack plugin for giFT

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../net/gift/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
