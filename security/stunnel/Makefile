# $NetBSD: Makefile,v 1.8 2001/01/13 18:41:33 jlam Exp $
#

DISTNAME=		stunnel-3.9
CATEGORIES=		security
MASTER_SITES=		http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		martin@NetBSD.ORG
HOMEPAGE=		http://www.stunnel.org/

BUILD_DEPENDS+=		autoconf:../../devel/autoconf
DEPENDS+=		pth>=1.3.5:../../devel/pth

USE_SSL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-cert-dir="${SSLCERTS}"

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../mk/bsd.pkg.mk"
