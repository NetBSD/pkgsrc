# $NetBSD: Makefile,v 1.22 2025/01/06 21:49:11 ktnb Exp $
#

DISTNAME=		digger-20020314
PKGREVISION=		8
CATEGORIES=		games
MASTER_SITES=		http://www.digger.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.digger.org/
COMMENT=		Digger Remastered

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:MLinux}
MAKE_FILE=		Makefile.sdl
USE_TOOLS+=		gmake
.else
MAKE_FILE=		Makefile.fbsd
MAKE_FLAGS+=		-DSDL
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digger ${DESTDIR}${PREFIX}/bin/digger

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
