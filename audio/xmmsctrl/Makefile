# $NetBSD: Makefile,v 1.9 2006/02/05 23:08:19 joerg Exp $
#

DISTNAME=		xmmsctrl-1.6
PKGREVISION=	2
CATEGORIES=		audio
MASTER_SITES=		http://www.docs.uu.se/~adavid/utils/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.docs.uu.se/~adavid/utils/
COMMENT=		Small utility to control xmms from the command line

USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin

.include "../../audio/xmms/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmmsctrl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
