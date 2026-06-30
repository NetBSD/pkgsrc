# $NetBSD: Makefile,v 1.20 2026/06/30 19:55:52 wiz Exp $

DISTNAME=	pim6dd-20031021a
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	IPv6 PIM dense mode daemon

USE_BSD_MAKEFILE=	yes
USE_FEATURES+=		inet6

CWARNFLAGS.clang=	-Wno-error=knr-promoted-parameter
CWARNFLAGS.clang+=	-Wno-error=address-of-packed-member
MAKE_ENV+=		CWARNFLAGS.clang=${CWARNFLAGS.clang:Q}
MAKE_FLAGS+=		PREFIX=${PREFIX}

CONFLICTS=	mcast-tools-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/pim6dd/

INSTALLATION_DIRS+=	${PKGMANDIR}/cat5 ${PKGMANDIR}/cat8
INSTALLATION_DIRS+=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.pkg.mk"
