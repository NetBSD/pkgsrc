# $NetBSD: Makefile,v 1.8 2024/05/06 08:40:22 jperkin Exp $

DISTNAME=	qodem-1.0.1
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qodem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qodem.sourceforge.net/
COMMENT=	Re-implementation of the DOS-era Qmodem serial communications package
LICENSE=	cc0-1.0-universal

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-gpm --disable-sdl --disable-upnp

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
