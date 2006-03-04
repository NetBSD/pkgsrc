# $NetBSD: Makefile,v 1.16 2006/03/04 21:29:42 jlam Exp $
#

DISTNAME=	lgeneral-1.1.1
PKGREVISION=	9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgeneral/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/index.php?project=LGeneral
COMMENT=	Panzer General play-a-like, uses Panzer General data files

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--disable-dl

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
