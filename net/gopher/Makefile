# $NetBSD: Makefile,v 1.8 2005/04/11 21:46:47 tv Exp $
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
USE_GNU_TOOLS+=	make
CONFIGURE_ARGS+=--disable-auth

.include "../../mk/bsd.pkg.mk"
