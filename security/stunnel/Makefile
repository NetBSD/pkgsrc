# $NetBSD: Makefile,v 1.3 2000/04/26 21:10:07 tron Exp $
#

DISTNAME=	stunnel-3.8
CATEGORIES=	security
MASTER_SITES=	http://mike.daewoo.com.pl/computer/stunnel/

MAINTAINER=	martin@NetBSD.ORG
HOMEPAGE=	http://mike.daewoo.com.pl/computer/stunnel

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf

GNU_CONFIGURE=	YES
USE_SSL=	YES
CONFIGURE_ARGS+=-with-ssl=${SSL_DIR}

BUILD_DEFS+=	OPENSSL_DIR

pre-configure:
	(cd ${WRKSRC}; autoreconf)

.include "../../mk/bsd.pkg.mk"
