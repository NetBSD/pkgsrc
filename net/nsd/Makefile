# $NetBSD: Makefile,v 1.2 2002/04/01 04:19:26 jmc Exp $

DISTNAME=	nsd-1.0-alpha
PKGNAME=	nsd-0.9
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

_FETCH_MESSAGE= \
	${ECHO} '======================================================='; \
	${ECHO} '  You need to get download password'; \
	${ECHO} '  and fetch on your own.'; \
	${ECHO} '======================================================='

.include "../../mk/bsd.pkg.mk"
