# $NetBSD: Makefile,v 1.37 2004/01/20 03:08:25 grant Exp $

DISTNAME=		stunnel-4.04
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.fu-berlin.de/unix/security/stunnel/ \
			ftp://stunnel.mirt.net/stunnel/ \
			http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel

USE_BUILDLINK2=		# defined
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE} \
			--with-cert-dir="${SSLCERTS}" \
			--with-pem-dir="${SSLCERTS}" \
			--with-tcp-wrappers \
			--sysconfdir="${PKG_SYSCONFDIR}" \
			--localstatedir=/var

PKG_SYSCONFSUBDIR=	stunnel

.include "../../security/openssl/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
