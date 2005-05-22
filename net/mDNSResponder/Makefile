# $NetBSD: Makefile,v 1.2 2005/05/22 20:08:25 jlam Exp $

DISTNAME=	mDNSResponder-62
CATEGORIES=	net
MASTER_SITES=	http://darwinsource.opendarwin.org/tarballs/apsl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://developer.apple.com/darwin/projects/rendezvous/
COMMENT=	Apple's mDNS repsonder

USE_TOOLS=	gmake
MAKE_ARGS+=	os=netbsd
WRKSRC=		${WRKDIR}/${DISTNAME}/mDNSPosix

BINARY=	mDNSClientPosix mDNSIdentify mDNSNetMonitor mDNSProxyResponderPosix \
	mDNSResponderPosix mdnsd

do-install:
	for i in ${BINARY}; do \
		${INSTALL_PROGRAM} ${WRKSRC}/build/prod/$$i ${PREFIX}/bin; \
	done

.include "../../mk/bsd.pkg.mk"
