# $NetBSD: Makefile,v 1.28 2001/11/20 15:15:14 martti Exp $

DISTNAME=		stunnel-3.21c
PKGNAME=		stunnel-3.21.3
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.fu-berlin.de/pub/unix/security/stunnel/ \
			ftp://stunnel.mirt.net/stunnel/ \
			http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		martti@netbsd.org
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel

USE_BUILDLINK_ONLY=	# defined
USE_SSL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE} \
			--with-cert-dir="${SSLCERTS}" \
			--with-pem-dir="${SSLCERTS}" \
			--with-tcp-wrappers

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
