# $NetBSD: Makefile,v 1.9 2004/05/27 18:18:07 wiz Exp $
# FreeBSD Id: Makefile,v 1.10 1998/12/22 16:07:01 tg Exp
#

DISTNAME=	xskat-3.4
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.gulu.net/xskat/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xskat.de/xskat.html
COMMENT=	Play the card game Skat

USE_IMAKE=	yes

.include "../../mk/bsd.pkg.mk"

.if defined(DEFAULT_IRC_SERVER)
MAKE_ENV+=	IRC_SERVER=${DEFAULT_IRC_SERVER}
.else
MAKE_ENV+=	IRC_SERVER=irc.fu-berlin.de
.endif
