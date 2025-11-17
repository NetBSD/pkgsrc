# $NetBSD: Makefile,v 1.9 2025/11/17 11:00:28 wiz Exp $

DISTNAME=	qodem-1.0.1
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qodem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qodem.sourceforge.net/
COMMENT=	Re-implementation of the DOS-era Qmodem serial communications package
LICENSE=	cc0-1.0-universal

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-gpm --disable-sdl --disable-upnp

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
