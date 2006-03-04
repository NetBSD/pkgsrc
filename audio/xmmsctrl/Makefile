# $NetBSD: Makefile,v 1.10 2006/03/04 21:29:00 jlam Exp $
#

DISTNAME=		xmmsctrl-1.6
PKGREVISION=	2
CATEGORIES=		audio
MASTER_SITES=		http://www.docs.uu.se/~adavid/utils/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.docs.uu.se/~adavid/utils/
COMMENT=		Small utility to control xmms from the command line

USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin

.include "../../audio/xmms/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmmsctrl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
