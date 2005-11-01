# $NetBSD: Makefile,v 1.5 2005/11/01 18:42:46 tv Exp $
#

DISTNAME=	sipcalc-1.1.2
CATEGORIES=	net
MASTER_SITES=	http://www.routemeister.net/projects/sipcalc/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.routemeister.net/projects/sipcalc/
COMMENT=	IPv4/IPv6 subnet calculator

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-web

.include "../../mk/bsd.prefs.mk"

.if empty(_OPSYS_HAS_INET6:M[Yy][Ee][Ss])
PKG_SKIP_REASON+=	"${PKGNAME} requires IPv6 support libraries"
.endif

.include "../../mk/bsd.pkg.mk"
