# $NetBSD: Makefile,v 1.10 2009/12/21 20:34:05 joerg Exp $
#

DISTNAME=	giFT-FastTrack-0.8.9
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/giFT-FastTrack/gift-fasttrack/}
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/gift-fasttrack/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gift-fasttrack.berlios.de/
COMMENT=	Fasttrack plugin for giFT

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../net/gift/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
