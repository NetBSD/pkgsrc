# $NetBSD: Makefile,v 1.1.1.1 2002/11/15 17:28:57 wiz Exp $
#

DISTNAME=	lgeneral-1.1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgeneral/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://lgames.sourceforge.net/index.php?project=LGeneral
COMMENT=	Panzer General play-a-like, uses Panzer General data files

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

CONFIGURE_ARGS+=	--disable-dl

.include "../../devel/SDL/buildlink2.mk"
.include "../../audio/SDL-mixer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
