# $NetBSD: Makefile,v 1.2 2000/01/27 17:07:28 pooka Exp $
# FreeBSD Id: Makefile,v 1.10 1998/12/22 16:07:01 tg Exp 
#

DISTNAME=	xskat-3.2
WRKSRC=		${WRKDIR}/xskat
CATEGORIES=	games
MASTER_SITES=	http://www.gulu.net/xskat/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gulu.net/xskat/

USE_IMAKE=	yes

.include "../../mk/bsd.pkg.mk"

.if defined(DEFAULT_IRC_SERVER)
MAKE_ENV+=	IRC_SERVER=${DEFAULT_IRC_SERVER}
.else
MAKE_ENV+=	IRC_SERVER=irc.fu-berlin.de
.endif
