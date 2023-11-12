# $NetBSD: Makefile,v 1.24 2023/11/12 13:21:45 wiz Exp $
#

DISTNAME=	wordwarvi-1.0.2
PKGREVISION=	21
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=smcameron/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://smcameron.github.io/wordwarvi/
COMMENT=	Side-scrolling shoot 'em up '80s style arcade game
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
