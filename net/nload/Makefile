# $NetBSD: Makefile,v 1.7 2015/08/17 17:11:28 wiz Exp $
#

DISTNAME=		nload-0.7.4
PKGREVISION=		1
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nload/}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.roland-riegel.de/nload/
COMMENT=		Monitoring network traffic and bandwidth usage
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
MANCOMPRESSED=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
