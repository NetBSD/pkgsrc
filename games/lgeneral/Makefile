# $NetBSD: Makefile,v 1.8 2003/12/08 14:41:39 wiz Exp $
#

DISTNAME=	lgeneral-1.1.1
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgeneral/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/index.php?project=LGeneral
COMMENT=	Panzer General play-a-like, uses Panzer General data files

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

CONFIGURE_ARGS+=	--disable-dl

.include "../../devel/SDL/buildlink2.mk"
.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
