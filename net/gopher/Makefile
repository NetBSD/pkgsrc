# $NetBSD: Makefile,v 1.9 2005/05/22 20:08:24 jlam Exp $
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
USE_TOOLS+=	gmake
CONFIGURE_ARGS+=--disable-auth

.include "../../mk/bsd.pkg.mk"
