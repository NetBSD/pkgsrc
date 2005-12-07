# $NetBSD: Makefile,v 1.8 2005/12/07 03:33:52 joerg Exp $
#

DISTNAME=	ripe-whois-tools-2.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ripe.net/tools/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.ripe.net/ripencc/pub-services/db/
COMMENT=	RIPE WHOIS client and tools

WRKSRC=		${WRKDIR}

LIBS.DragonFly+=-lcrypt
LIBS.NetBSD+=	-lcrypt
LIBS.SunOS+=	-lnsl -lsocket

MAKE_ENV+=	LIBS=${LIBS:M*:Q}

.include "../../mk/bsd.pkg.mk"
