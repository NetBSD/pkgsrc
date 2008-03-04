# $NetBSD: Makefile,v 1.16 2008/03/04 06:59:03 jlam Exp $
#

DISTNAME=		digger-20020314
PKGREVISION=		5
CATEGORIES=		games
MASTER_SITES=		http://www.digger.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.digger.org/
COMMENT=		Digger Remastered

PKG_DESTDIR_SUPPORT=	user-destdir

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
.include "../../mk/bsd.pkg.mk"
