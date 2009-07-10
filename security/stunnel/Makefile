# $NetBSD: Makefile,v 1.66 2009/07/10 11:23:10 tron Exp $

DISTNAME=		stunnel-4.27
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.fu-berlin.de/unix/security/stunnel/ \
			ftp://stunnel.mirt.net/stunnel/ \
			http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		shaun@inerd.com
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-cert-dir=${SSLCERTS:Q}
CONFIGURE_ARGS+=	--with-pem-dir=${SSLCERTS:Q}
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}

PKG_SYSCONFSUBDIR=	stunnel

RCD_SCRIPTS=		stunnel
REPLACE_PERL+=		src/stunnel3.in
USE_TOOLS+=		perl:run

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
