# $NetBSD: Makefile,v 1.61 2008/01/18 05:09:42 tnn Exp $

DISTNAME=		stunnel-4.20
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.fu-berlin.de/unix/security/stunnel/ \
			ftp://stunnel.mirt.net/stunnel/ \
			http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		shaun@inerd.com
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q} \
			--with-cert-dir=${SSLCERTS:Q} \
			--with-pem-dir=${SSLCERTS:Q} \
			--with-tcp-wrappers \
			--sysconfdir=${PKG_SYSCONFDIR:Q} \
			--localstatedir=${VARBASE:Q}

PTHREAD_OPTS?=		optional

PKG_SYSCONFSUBDIR=	stunnel

RCD_SCRIPTS=		stunnel
REPLACE_PERL+=		src/stunnel3.in
USE_TOOLS+=		perl:run

.include "../../mk/pthread.buildlink3.mk"

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
