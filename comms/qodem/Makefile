# $NetBSD: Makefile,v 1.4 2021/03/16 17:00:40 fcambus Exp $

DISTNAME=	qodem-1.0.1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qodem/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	http://qodem.sourceforge.net/
COMMENT=	Re-implementation of the DOS-era Qmodem serial communications package
LICENSE=	cc0-1.0-universal

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-sdl --disable-upnp

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--disable-gpm
.endif

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
