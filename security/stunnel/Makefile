# $NetBSD: Makefile,v 1.30 2002/06/17 10:47:56 wiz Exp $

DISTNAME=		stunnel-3.22
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.fu-berlin.de/pub/unix/security/stunnel/ \
			ftp://stunnel.mirt.net/stunnel/ \
			http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		martti@netbsd.org
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE} \
			--with-cert-dir="${SSLCERTS}" \
			--with-pem-dir="${SSLCERTS}" \
			--with-tcp-wrappers

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
