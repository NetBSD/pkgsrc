# $NetBSD: Makefile,v 1.12 2001/02/05 09:01:03 tron Exp $
#

DISTNAME=		stunnel-3.13
CATEGORIES=		security
MASTER_SITES=		http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		martin@NetBSD.ORG
HOMEPAGE=		http://www.stunnel.org/

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf
DEPENDS+=		pth>=1.3.5:../../devel/pth

USE_SSL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE} \
			--with-cert-dir="${SSLCERTS}" \
			--with-pem-dir="${SSLCERTS}"

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoremake

.include "../../mk/bsd.pkg.mk"
