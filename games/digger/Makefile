# $NetBSD: Makefile,v 1.4 2005/03/23 14:31:26 wiz Exp $
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
.else
MAKEFILE=		Makefile.fbsd
.endif
MAKE_FLAGS+=		-DSDL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digger ${PREFIX}/bin/digger

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
