# $NetBSD: Makefile,v 1.5 2012/03/06 17:39:01 ryoon Exp $

DISTNAME=	pkcs11-helper-1.08
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/pkcs11-helper/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opensc-project.org/opensc/wiki/pkcs11-helper
COMMENT=	Library that simplifies the interaction with PKCS\#11
LICENSE=	modified-bsd OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf autoreconf gmake pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	lib/libpkcs11-helper-1.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
