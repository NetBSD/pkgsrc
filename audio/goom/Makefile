# $NetBSD: Makefile,v 1.1.1.1 2005/02/20 14:59:24 wiz Exp $
#

DISTNAME=		goom-2k4-0-src
PKGNAME=		goom-2004.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=goom/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ios-software.com/index.php3?page=projet&quoi=1&lg=AN
COMMENT=		Visual effects generator for mp3 players

WRKSRC=			${WRKDIR}/goom2k4-0
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgoom2.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
