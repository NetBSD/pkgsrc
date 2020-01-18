# $NetBSD: Makefile,v 1.2 2020/01/18 23:30:13 rillig Exp $

DISTNAME=	qodem-1.0.0
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qodem/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://qodem.sourceforge.net/
COMMENT=	Re-implementation of the DOS-era Qmodem serial communications package
LICENSE=	cc0-1.0-universal

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-sdl --disable-upnp

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
