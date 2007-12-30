# $NetBSD: Makefile,v 1.3 2007/12/30 14:25:13 obache Exp $

DISTNAME=		hcidump-1.5.1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.geocities.com/m_evmenkin/

MAINTAINER=		plunky@rya-online.net
COMMENT=		Bluetooth traffic dumper, similar to tcpdump

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*	\
			NetBSD-3.99.[2-9][0-9]-*

WRKSRC=			${WRKDIR}/hcidump

INSTALLATION_DIRS+=	${PKGMANDIR}/cat1
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.pkg.mk"
