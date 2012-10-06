# $NetBSD: Makefile,v 1.18 2012/10/06 11:54:35 asau Exp $

DISTNAME=	defendguin-0.0.10
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/defendguin/src/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.newbreedsoftware.com/defendguin/
COMMENT=	Clone of the arcade game Defender

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
