# $NetBSD: Makefile,v 1.6 2000/06/17 21:21:49 tron Exp $
#

DISTNAME=	stunnel-3.8
CATEGORIES=	security
MASTER_SITES=	http://mike.daewoo.com.pl/computer/stunnel/

MAINTAINER=	martin@NetBSD.ORG
HOMEPAGE=	http://mike.daewoo.com.pl/computer/stunnel

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
DEPENDS+=	pth>=1.3.5:../../devel/pth

GNU_CONFIGURE=	YES
USE_SSL=	YES
CONFIGURE_ARGS+=-with-ssl=${SSLBASE}

pre-configure:
	(cd ${WRKSRC}; autoreconf)

.include "../../mk/bsd.pkg.mk"
