# $NetBSD: Makefile,v 1.2 2004/06/14 00:58:44 grant Exp $
#

DISTNAME=		xmmsctrl-1.6
CATEGORIES=		audio
MASTER_SITES=		http://www.docs.uu.se/~adavid/utils/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.docs.uu.se/~adavid/utils/
COMMENT=		Small utility to control xmms from the command line

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmmsctrl ${PREFIX}/bin

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
