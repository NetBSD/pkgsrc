# $NetBSD: Makefile,v 1.3 2004/06/14 01:09:05 grant Exp $
#

DISTNAME=		xmmsctrl-1.6
CATEGORIES=		audio
MASTER_SITES=		http://www.docs.uu.se/~adavid/utils/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.docs.uu.se/~adavid/utils/
COMMENT=		Small utility to control xmms from the command line

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make

.include "../../audio/xmms/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmmsctrl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
