# $NetBSD: Makefile,v 1.25 2001/11/01 08:23:02 tron Exp $

DISTNAME=		stunnel-3.21a
PKGNAME=		stunnel-3.21.1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.fu-berlin.de/pub/unix/security/stunnel/ \
			ftp://stunnel.mirt.net/stunnel/ \
			http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		martin@NetBSD.ORG
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf

USE_BUILDLINK_ONLY=	# defined
USE_SSL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE} \
			--with-cert-dir="${SSLCERTS}" \
			--with-pem-dir="${SSLCERTS}" \
			--with-tcp-wrappers

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
