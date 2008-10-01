# $NetBSD: Makefile,v 1.64 2008/10/01 14:34:32 obache Exp $

DISTNAME=		stunnel-4.24
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.fu-berlin.de/unix/security/stunnel/ \
			ftp://stunnel.mirt.net/stunnel/ \
			http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		shaun@inerd.com
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q} \
			--with-cert-dir=${SSLCERTS:Q} \
			--with-pem-dir=${SSLCERTS:Q} \
			--sysconfdir=${PKG_SYSCONFDIR:Q} \
			--localstatedir=${VARBASE:Q}

PKG_SYSCONFSUBDIR=	stunnel

RCD_SCRIPTS=		stunnel
REPLACE_PERL+=		src/stunnel3.in
USE_TOOLS+=		perl:run

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
