# $NetBSD: Makefile,v 1.22 2026/08/04 20:28:55 wiz Exp $

DISTNAME=	defendguin-0.0.12
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/defendguin/src/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.newbreedsoftware.com/defendguin/
COMMENT=	Clone of the arcade game Defender

LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
