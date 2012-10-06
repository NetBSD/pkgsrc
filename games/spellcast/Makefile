# $NetBSD: Makefile,v 1.14 2012/10/06 11:54:55 asau Exp $
#

DISTNAME=		spellcast
PKGNAME=		spellcast-1.2
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://www.eblong.com/zarf/ftp/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.eblong.com/zarf/spellcast.html
COMMENT=		Game of dueling wizards for two players

USE_X11BASE=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
