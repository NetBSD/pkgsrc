# $NetBSD: Makefile,v 1.10 2001/01/22 16:31:49 tron Exp $
#

DISTNAME=		stunnel-3.11
CATEGORIES=		security
MASTER_SITES=		http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		martin@NetBSD.ORG
HOMEPAGE=		http://www.stunnel.org/

BUILD_DEPENDS+=		autoconf:../../devel/autoconf
DEPENDS+=		pth>=1.3.5:../../devel/pth

USE_SSL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE} \
			--with-cert-dir="${SSLCERTS}" \
			--with-pem-dir="${SSLCERTS}"

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../mk/bsd.pkg.mk"
