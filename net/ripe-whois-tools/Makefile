# $NetBSD: Makefile,v 1.2 2001/05/18 11:56:00 rh Exp $
#

DISTNAME=	ripe-whois-tools-2.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ripe.net/tools/

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://www.ripe.net/ripencc/pub-services/db/
COMMENT=	RIPE WHOIS client and tools

WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
EXTRA_LIBS=	-lcrypt
.endif

MAKE_ENV+=	EXTRA_LIBS=${EXTRA_LIBS}

.include "../../mk/bsd.pkg.mk"
