# $NetBSD: Makefile,v 1.3 2011/04/22 14:40:45 obache Exp $
#

DISTNAME=	pkcs11-helper-1.06
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/pkcs11-helper/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opensc-project.org/pkcs11-helper/
COMMENT=	Library that simplifies the interaction with PKCS\#11
LICENSE=	modified-bsd # OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf gmake autoreconf

PKGCONFIG_OVERRIDE+=	lib/libpkcs11-helper-1.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
