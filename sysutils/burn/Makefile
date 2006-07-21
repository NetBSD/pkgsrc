# $NetBSD: Makefile,v 1.12 2006/07/21 05:17:30 rillig Exp $
#

DISTNAME=	burn-0.4.0
PKGREVISION=	5
CATEGORIES=	sysutils gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gsburn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gsburn.sourceforge.net/
COMMENT=	GNUstep based CD burning program

DEPENDS+=	cdparanoia>=3.0.9.8:../../audio/cdparanoia
DEPENDS+=	cdrtools>=1.10:../../sysutils/cdrtools
DEPENDS+=	cdrdao>=1.1.5:../../sysutils/cdrdao
DEPENDS+=	gworkspace-[0-9]*:../../sysutils/gworkspace

NO_CONFIGURE=	YES
MAKEFILE=	GNUmakefile
USE_TOOLS+=	gmake
USE_LANGUAGES=	c objc
WRKSRC=		${WRKDIR}/${PKGBASE}
MAKE_ENV+=	ADDITIONAL_CPPFLAGS=-D_POSIX_SOURCE
MAKE_ENV+=	ADDITIONAL_LDFLAGS=-lutil

.include "../../audio/cdplayer/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
