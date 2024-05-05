# $NetBSD: Makefile,v 1.1 2024/05/05 08:53:21 nia Exp $

DISTNAME=	d0_blind_id-1.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=divVerent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/divVerent/d0_blind_id
COMMENT=	Library to perform identification using Blind RSA Signatures
LICENSE=	modified-bsd

USE_TOOLS+=	autoreconf autoconf automake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	d0_blind_id.pc.in
PKGCONFIG_OVERRIDE+=	d0_rijndael.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
