# $NetBSD: Makefile,v 1.49 2005/07/03 04:00:18 tv Exp $

DISTNAME=		stunnel-4.07
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.fu-berlin.de/unix/security/stunnel/ \
			ftp://stunnel.mirt.net/stunnel/ \
			http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel

USE_PKGINSTALL=		yes
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE} \
			--with-cert-dir="${SSLCERTS}" \
			--with-pem-dir="${SSLCERTS}" \
			--with-tcp-wrappers \
			--sysconfdir="${PKG_SYSCONFDIR}" \
			--localstatedir=${VARBASE}

PKG_SYSCONFSUBDIR=	stunnel

RCD_SCRIPTS=		stunnel
REPLACE_PERL=		src/stunnel3.in

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
