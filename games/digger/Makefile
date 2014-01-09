# $NetBSD: Makefile,v 1.19 2014/01/09 14:50:09 jperkin Exp $
#

DISTNAME=		digger-20020314
PKGREVISION=		6
CATEGORIES=		games
MASTER_SITES=		http://www.digger.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.digger.org/
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
