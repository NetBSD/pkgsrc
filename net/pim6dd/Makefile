# $NetBSD: Makefile,v 1.18 2013/09/10 14:36:37 joerg Exp $

DISTNAME=	pim6dd-20031021a
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	IPv6 PIM dense mode daemon

USE_BSD_MAKEFILE=	yes
USE_FEATURES+=		inet6

MAKE_ENV+=	CWARNFLAGS.clang=-Wno-error=knr-promoted-parameter

CONFLICTS=	mcast-tools-*

WRKSRC=		${WRKDIR}/${DISTNAME}/pim6dd/

INSTALLATION_DIRS=	${PKGMANDIR}/cat5 ${PKGMANDIR}/cat8 \
			${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.pkg.mk"
