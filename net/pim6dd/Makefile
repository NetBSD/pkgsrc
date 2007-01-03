# $NetBSD: Makefile,v 1.11 2007/01/03 15:23:25 tv Exp $

DISTNAME=	pim6dd-20031021a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	IPv6 PIM dense mode daemon

WRKSRC=		${WRKDIR}/${DISTNAME}/pim6dd/

PKG_OPTIONS_VAR=		PKG_OPTIONS.pim6dd
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
