# $NetBSD: Makefile,v 1.7 2012/11/21 23:32:35 gdt Exp $

DISTNAME=	pkcs11-helper-1.08
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/pkcs11-helper/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.opensc-project.org/opensc/wiki/pkcs11-helper
COMMENT=	Library that simplifies the interaction with PKCS\#11
LICENSE=	modified-bsd OR gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf autoreconf gmake pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	lib/libpkcs11-helper-1.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
