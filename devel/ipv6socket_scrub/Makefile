# $NetBSD: Makefile,v 1.6 2000/03/16 12:25:49 wiz Exp $
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

DECOMPRESS_CMD=		${CAT}
EXTRACT_BEFORE_ARGS=	-xf
WRKSRC=			${WRKDIR}/${DISTNAME}/src
NO_CDROM=		"not redistributable"
NO_PACKAGE=		"not redistributable"
RESTRICTED=		"not redistributable, license agreement required"
MIRROR_DISTFILES=	no

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
