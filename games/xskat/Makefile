# $NetBSD: Makefile,v 1.7 2003/06/02 01:19:34 jschauma Exp $
# FreeBSD Id: Makefile,v 1.10 1998/12/22 16:07:01 tg Exp
#

DISTNAME=	xskat-3.4
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.gulu.net/xskat/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.gulu.net/xskat/
COMMENT=	Play the card game Skat

USE_IMAKE=	yes

.include "../../mk/bsd.pkg.mk"

.if defined(DEFAULT_IRC_SERVER)
MAKE_ENV+=	IRC_SERVER=${DEFAULT_IRC_SERVER}
.else
MAKE_ENV+=	IRC_SERVER=irc.fu-berlin.de
.endif
