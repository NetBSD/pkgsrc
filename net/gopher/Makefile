# $NetBSD: Makefile,v 1.6.4.1 2004/07/30 16:03:44 agc Exp $
#

DISTNAME=	gopher_3.0.6
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://gopher.quux.org:70/give-me-gopher/

MAINTAINER=	jgoerzen@complete.org
HOMEPAGE=	gopher://quux.org/1/devel/gopher/
COMMENT=	Distributed document delivery client and server

WRKSRC=		${WRKDIR}/gopher
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
CONFIGURE_ARGS+=--disable-auth

.include "../../mk/bsd.pkg.mk"
