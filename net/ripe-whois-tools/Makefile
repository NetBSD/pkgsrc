# $NetBSD: Makefile,v 1.5 2004/01/27 13:40:03 grant Exp $
#

DISTNAME=	ripe-whois-tools-2.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ripe.net/tools/

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://www.ripe.net/ripencc/pub-services/db/
COMMENT=	RIPE WHOIS client and tools

WRKSRC=		${WRKDIR}

LIBS.NetBSD=	-lcrypt
LIBS.SunOS=	-lnsl -lsocket

MAKE_ENV+=	LIBS="${LIBS}"

.include "../../mk/bsd.pkg.mk"
