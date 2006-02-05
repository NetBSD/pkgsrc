# $NetBSD: Makefile,v 1.12 2006/02/05 23:09:14 joerg Exp $
#

DISTNAME=		digger-20020314
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=		http://www.digger.org/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.digger.org/
COMMENT=		Digger Remastered


.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:MLinux}
MAKEFILE=		Makefile.sdl
USE_TOOLS+=		gmake
.else
MAKEFILE=		Makefile.fbsd
MAKE_FLAGS+=		-DSDL
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digger ${PREFIX}/bin/digger

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
