# $NetBSD: Makefile,v 1.3 2002/04/03 03:44:32 itojun Exp $

DISTNAME=	nsd-1.0-alpha2
PKGNAME=	nsd-0.9.2
CATEGORIES=	net
#MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nlnetlabs.nl/nsd/index.en.html
COMMENT=	authoritative-only DNS server
RESTRICTED=	No redistribution of source or binaries (alpha release)
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

WRKSRC=		${WRKDIR}/nsd

_FETCH_MESSAGE= \
	${ECHO} '======================================================='; \
	${ECHO} '  You need to get download password'; \
	${ECHO} '  and fetch on your own.'; \
	${ECHO} '======================================================='

.include "../../mk/bsd.pkg.mk"
