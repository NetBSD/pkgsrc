# $NetBSD: Makefile,v 1.29 2001/12/28 07:22:29 tron Exp $

DISTNAME=		stunnel-3.22
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
