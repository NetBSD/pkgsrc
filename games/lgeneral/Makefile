# $NetBSD: Makefile,v 1.14 2005/12/11 09:40:42 wiz Exp $
#

DISTNAME=	lgeneral-1.1.1
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgeneral/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/index.php?project=LGeneral
COMMENT=	Panzer General play-a-like, uses Panzer General data files

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--disable-dl

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
