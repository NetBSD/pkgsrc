# $NetBSD: Makefile,v 1.40 2004/04/25 03:12:29 snj Exp $

DISTNAME=		stunnel-4.05
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.fu-berlin.de/unix/security/stunnel/ \
			ftp://stunnel.mirt.net/stunnel/ \
			http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE} \
			--with-cert-dir="${SSLCERTS}" \
			--with-pem-dir="${SSLCERTS}" \
			--with-tcp-wrappers \
			--sysconfdir="${PKG_SYSCONFDIR}" \
			--localstatedir=/var

PKG_SYSCONFSUBDIR=	stunnel

.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
