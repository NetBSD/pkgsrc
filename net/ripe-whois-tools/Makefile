# $NetBSD: Makefile,v 1.6 2005/10/12 07:10:57 seb Exp $
#

DISTNAME=	ripe-whois-tools-2.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ripe.net/tools/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.ripe.net/ripencc/pub-services/db/
COMMENT=	RIPE WHOIS client and tools

WRKSRC=		${WRKDIR}

LIBS.NetBSD=	-lcrypt
LIBS.SunOS=	-lnsl -lsocket

MAKE_ENV+=	LIBS="${LIBS}"

.include "../../mk/bsd.pkg.mk"
