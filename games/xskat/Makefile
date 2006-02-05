# $NetBSD: Makefile,v 1.12 2006/02/05 23:09:25 joerg Exp $

DISTNAME=	xskat-3.4
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.gulu.net/xskat/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xskat.de/xskat.html
COMMENT=	Play the card game Skat

USE_IMAKE=	yes

.include "../../mk/bsd.pkg.mk"

.if defined(DEFAULT_IRC_SERVER)
MAKE_ENV+=	IRC_SERVER=${DEFAULT_IRC_SERVER:Q}
.else
MAKE_ENV+=	IRC_SERVER=irc.fu-berlin.de
.endif
