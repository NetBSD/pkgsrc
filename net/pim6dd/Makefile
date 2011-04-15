# $NetBSD: Makefile,v 1.16 2011/04/15 07:51:24 obache Exp $

DISTNAME=	pim6dd-20031021a
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	IPv6 PIM dense mode daemon

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes
USE_FEATURES+=		inet6

CONFLICTS=	mcast-tools-*

WRKSRC=		${WRKDIR}/${DISTNAME}/pim6dd/

INSTALLATION_DIRS=	${PKGMANDIR}/cat5 ${PKGMANDIR}/cat8 \
			${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.pkg.mk"
