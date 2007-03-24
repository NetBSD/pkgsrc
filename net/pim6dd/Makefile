# $NetBSD: Makefile,v 1.12 2007/03/24 19:21:30 joerg Exp $

DISTNAME=	pim6dd-20031021a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	IPv6 PIM dense mode daemon

WRKSRC=		${WRKDIR}/${DISTNAME}/pim6dd/

PKG_OPTIONS_VAR=		PKG_OPTIONS.pim6dd
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

INSTALLATION_DIRS=	${PKGMANDIR}/cat5 ${PKGMANDIR}/cat8 \
			${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
