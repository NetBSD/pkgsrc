# $NetBSD: Makefile,v 1.5 2004/01/20 12:22:19 agc Exp $
#

DISTNAME=	gopher_3.0.6
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://gopher.quux.org:70/give-me-gopher/

MAINTAINER=	jgoerzen@complete.org
HOMEPAGE=	gopher://quux.org/1/devel/gopher/
COMMENT=	Distributed document delivery client and server

WRKSRC=		${WRKDIR}/gopher
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
CONFIGURE_ARGS+= --disable-auth

.include "../../mk/bsd.pkg.mk"
