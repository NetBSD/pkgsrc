# $NetBSD: Makefile,v 1.9 2001/02/16 14:38:31 wiz Exp $
# KAME Id: Makefile,v 1.6 1999/11/28 14:36:04 itojun Exp
#

DISTNAME=		IPv6socket_scrub
PKGNAME=		ipv6socket_scrub-1.0
CATEGORIES=		devel
# need to fetch on your own
#MASTER_SITES=		
EXTRACT_SUFX=		.tar

MAINTAINER=		itojun@kame.net
HOMEPAGE=		http://www.sun.com/solaris/ipv6/
COMMENT=		checks IPv6 portability in source code

DECOMPRESS_CMD=		${CAT}
EXTRACT_BEFORE_ARGS=	-xf
WRKSRC=			${WRKDIR}/${DISTNAME}/src
RESTRICTED=		"not redistributable, license agreement required"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

do-fetch:
	@if ${TEST} \! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}; then \
		${ECHO} "===> You need to sign the agreement on ${HOMEPAGE}"; \
		${ECHO} "     and fetch on your own."; \
		exit 1; \
	fi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipv6socket_scrub ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../Docs/man/man1/ipv6socket_scrub.1 \
		${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
