# $NetBSD: Makefile,v 1.26 2001/11/02 08:13:19 martti Exp $

DISTNAME=		stunnel-3.21a
PKGNAME=		stunnel-3.21.1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.fu-berlin.de/pub/unix/security/stunnel/ \
			ftp://stunnel.mirt.net/stunnel/ \
			http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		martti@netbsd.org
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
