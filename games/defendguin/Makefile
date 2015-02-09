# $NetBSD: Makefile,v 1.19 2015/02/09 09:51:26 snj Exp $

DISTNAME=	defendguin-0.0.12
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/defendguin/src/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.newbreedsoftware.com/defendguin/
COMMENT=	Clone of the arcade game Defender

LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
