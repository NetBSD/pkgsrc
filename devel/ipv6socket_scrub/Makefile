# $NetBSD: Makefile,v 1.14 2003/07/21 16:43:24 martti Exp $
# KAME Id: Makefile,v 1.6 1999/11/28 14:36:04 itojun Exp
#

DISTNAME=		IPv6socket_scrub
PKGNAME=		ipv6socket_scrub-1.0
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		devel
# need to fetch on your own
#MASTER_SITES=		
EXTRACT_SUFX=		.tar

MAINTAINER=		itojun@kame.net
HOMEPAGE=		http://www.sun.com/solaris/ipv6/
COMMENT=		Checks IPv6 portability in source code

DECOMPRESS_CMD=		${CAT}
EXTRACT_BEFORE_ARGS=	-xf
RESTRICTED=		"not redistributable, license agreement required"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

INTERACTIVE_STAGE=	fetch

_FETCH_MESSAGE= \
	${ECHO} '======================================================='; \
	${ECHO} '  You need to sign the agreement on ${HOMEPAGE}'; \
	${ECHO} '  and fetch on your own.'; \
	${ECHO} '======================================================='

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipv6socket_scrub ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../Docs/man/man1/ipv6socket_scrub.1 \
		${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
