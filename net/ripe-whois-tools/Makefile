# $NetBSD: Makefile,v 1.3 2003/03/29 12:42:03 jmmv Exp $
#

DISTNAME=	ripe-whois-tools-2.4
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ripe.net/tools/

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://www.ripe.net/ripencc/pub-services/db/
COMMENT=	RIPE WHOIS client and tools

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
EXTRA_LIBS=	-lcrypt
.endif

MAKE_ENV+=	EXTRA_LIBS=${EXTRA_LIBS}

.include "../../mk/bsd.pkg.mk"
