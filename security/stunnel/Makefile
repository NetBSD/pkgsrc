# $NetBSD: Makefile,v 1.14 2001/02/17 17:50:12 wiz Exp $
#

DISTNAME=		stunnel-3.13
CATEGORIES=		security
MASTER_SITES=		http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		martin@NetBSD.ORG
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoreconf:../../devel/autoconf
DEPENDS+=		pth>=1.3.5:../../devel/pth

USE_SSL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE} \
			--with-cert-dir="${SSLCERTS}" \
			--with-pem-dir="${SSLCERTS}"

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

.include "../../mk/bsd.pkg.mk"
