# $NetBSD: Makefile,v 1.22 2020/05/22 10:56:36 adam Exp $

VERSION=	0.9.2
DISTNAME=	gnupg-pkcs11-scd-${VERSION}
#PKGREVISION=	1
PKGREVISION=	3
CATEGORIES=	security
GITHUB_PROJECT=	gnupg-pkcs11-scd
GITHUB_RELEASE=	${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=alonbl/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnupg-pkcs11.sourceforge.net/
COMMENT=	OpenSC smart card support for GnuPG
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
LIBS.OperatingSystem+=	-ldl
CONFIGURE_ARGS+=	--with-libgpg-error-prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-libassuan-prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-libgcrypt-prefix=${PREFIX}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/pkcs11-helper/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
