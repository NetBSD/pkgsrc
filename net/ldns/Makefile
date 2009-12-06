# $NetBSD: Makefile,v 1.8 2009/12/06 15:29:36 wiz Exp $

DISTNAME=	ldns-1.6.3
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/drill/
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/ldns/

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/projects/ldns/
COMMENT=	Library for simplified DNS programming
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-sha2

REPLACE_PERL=	doc/doxyparse.pl

BUILDLINK_ABI_DEPENDS.openssl+= openssl>=0.9.8
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
