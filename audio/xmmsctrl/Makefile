# $NetBSD: Makefile,v 1.11 2006/10/04 20:44:20 wiz Exp $
#

DISTNAME=		xmmsctrl-1.6
PKGREVISION=	2
CATEGORIES=		audio
MASTER_SITES=		http://user.it.uu.se/~adavid/utils/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://user.it.uu.se/~adavid/utils/
COMMENT=		Small utility to control xmms from the command line

USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin

.include "../../audio/xmms/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmmsctrl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
