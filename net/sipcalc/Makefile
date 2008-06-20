# $NetBSD: Makefile,v 1.9 2008/06/20 01:09:31 joerg Exp $
#

DISTNAME=	sipcalc-1.1.3
CATEGORIES=	net
MASTER_SITES=	http://www.routemeister.net/projects/sipcalc/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.routemeister.net/projects/sipcalc/
COMMENT=	IPv4/IPv6 subnet calculator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

PKG_OPTIONS_VAR=		PKG_OPTIONS.sipcalc
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
