# $NetBSD: Makefile,v 1.1.1.1 2000/04/03 09:25:35 martin Exp $
#

DISTNAME=	stunnel-3.8
CATEGORIES=	security
MASTER_SITES=	http://mike.daewoo.com.pl/computer/stunnel/

MAINTAINER=	martin@NetBSD.ORG
HOMEPAGE=	http://mike.daewoo.com.pl/computer/stunnel

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf

.if exists(/usr/include/openssl/ssl.h)
OPENSSL_DIR=    /usr
.else
OPENSSL_DIR=    ${LOCALBASE}
DEPENDS+=       openssl>=0.9.4:../openssl
.endif

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=-with-ssl=${OPENSSL_DIR}

pre-configure:
	(cd ${WRKSRC}; autoreconf)

.include "../../mk/bsd.pkg.mk"
