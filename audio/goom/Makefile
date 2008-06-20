# $NetBSD: Makefile,v 1.8 2008/06/20 01:09:05 joerg Exp $
#

DISTNAME=		goom-2k4-0-src
PKGNAME=		goom-2004.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=goom/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ios-software.com/index.php3?page=projet&quoi=1&lg=AN
COMMENT=		Visual effects generator for mp3 players

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/goom2k4-0
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgoom2.pc.in
GNU_CONFIGURE=		yes
GCC_REQD+=		3.3
USE_TOOLS+=		pkg-config

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
