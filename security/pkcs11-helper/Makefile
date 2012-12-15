# $NetBSD: Makefile,v 1.9 2012/12/15 10:36:20 ryoon Exp $

DISTNAME=	pkcs11-helper-1.10
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/downloads/alonbl/pkcs11-helper/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.opensc-project.org/opensc/wiki/pkcs11-helper
COMMENT=	Library that simplifies the interaction with PKCS\#11
LICENSE=	modified-bsd OR gnu-gpl-v2

FETCH_USING=		curl
# Not documented, but relatively clear from warnings.
USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf autoreconf gmake pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-strict
CONFIGURE_ARGS+=	--enable-pedantic

PKGCONFIG_OVERRIDE+=	lib/libpkcs11-helper-1.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
