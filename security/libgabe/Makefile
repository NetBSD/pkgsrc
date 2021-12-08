# $NetBSD: Makefile,v 1.2 2021/12/08 16:02:34 adam Exp $

DISTNAME=	libgabe-1.0
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=schanzen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/schanzen/libgabe
COMMENT=	Ciphertext-Policy Attribute-Based Encryption library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libpbc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
