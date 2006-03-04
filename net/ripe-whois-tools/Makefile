# $NetBSD: Makefile,v 1.10 2006/03/04 21:30:24 jlam Exp $
#

DISTNAME=	ripe-whois-tools-2.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ripe.net/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ripe.net/ripencc/pub-services/db/
COMMENT=	RIPE WHOIS client and tools

WRKSRC=		${WRKDIR}

LIBS.DragonFly+=-lcrypt
LIBS.NetBSD+=	-lcrypt
LIBS.SunOS+=	-lnsl -lsocket

MAKE_ENV+=	LIBS=${LIBS:M*:Q}

.include "../../mk/bsd.pkg.mk"
