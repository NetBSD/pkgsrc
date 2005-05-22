# $NetBSD: Makefile,v 1.6 2005/05/22 20:07:40 jlam Exp $
#

DISTNAME=		xmmsctrl-1.6
PKGREVISION=	1
CATEGORIES=		audio
MASTER_SITES=		http://www.docs.uu.se/~adavid/utils/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.docs.uu.se/~adavid/utils/
COMMENT=		Small utility to control xmms from the command line

USE_TOOLS+=		gmake

.include "../../audio/xmms/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmmsctrl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
