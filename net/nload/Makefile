# $NetBSD: Makefile,v 1.4 2010/03/30 11:17:45 obache Exp $
#

DISTNAME=		nload-0.7.2
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nload/}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.roland-riegel.de/nload/
COMMENT=		Monitoring network traffic and bandwidth usage
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
MANCOMPRESSED=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
