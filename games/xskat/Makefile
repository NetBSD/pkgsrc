# $NetBSD: Makefile,v 1.14 2006/12/27 13:37:37 joerg Exp $

DISTNAME=	xskat-3.4
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.gulu.net/xskat/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xskat.de/xskat.html
COMMENT=	Play the card game Skat

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(DEFAULT_IRC_SERVER)
MAKE_ENV+=	IRC_SERVER=${DEFAULT_IRC_SERVER:Q}
.else
MAKE_ENV+=	IRC_SERVER=irc.fu-berlin.de
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
