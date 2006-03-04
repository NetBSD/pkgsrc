# $NetBSD: Makefile,v 1.6 2006/03/04 21:30:18 jlam Exp $
#

DISTNAME=	giFT-FastTrack-0.8.9
PKGNAME=	${DISTNAME:S/giFT-FastTrack/gift-fasttrack/}
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/gift-fasttrack/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.berlios.de/gift-fasttrack/
COMMENT=	Fasttrack plugin for giFT

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../net/gift/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
