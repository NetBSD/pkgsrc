# $NetBSD: Makefile,v 1.6 2005/03/26 10:39:41 wiz Exp $
#

DISTNAME=		digger-20020314
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://www.digger.org/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.digger.org/
COMMENT=		Digger Remastered

USE_BUILDLINK3=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:MLinux}
MAKEFILE=		Makefile.sdl
USE_GNU_TOOLS+=		make
.else
MAKEFILE=		Makefile.fbsd
MAKE_FLAGS+=		-DSDL
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digger ${PREFIX}/bin/digger

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
