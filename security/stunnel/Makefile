# $NetBSD: Makefile,v 1.57 2006/10/16 20:14:26 tv Exp $

DISTNAME=		stunnel-4.15
PKGREVISION=		1
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

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--with-threads=fork
.else
CONFIGURE_ARGS+=	--with-threads=pthread
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS}" \
			LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
