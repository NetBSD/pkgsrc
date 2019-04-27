# $NetBSD: Makefile,v 1.19 2019/04/27 11:25:11 wiz Exp $

DISTNAME=	xskat-4.0
CATEGORIES=	games
MASTER_SITES=	http://www.xskat.de/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

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
