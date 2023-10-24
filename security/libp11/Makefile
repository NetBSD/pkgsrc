# $NetBSD: Makefile,v 1.17 2023/10/24 22:10:50 wiz Exp $
#

DISTNAME=		libp11-0.4.11
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=OpenSC/}
GITHUB_RELEASE=		${DISTNAME}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/OpenSC/libp11/wiki
COMMENT=		Convenience library for easy PKCS\#11 implementation
LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	src/libp11.pc.in

CONFIGURE_ARGS+=	--with-enginesdir=${PREFIX}/lib/engines-1.1

CHECK_PORTABILITY_SKIP+=	tests/search-all-matching-tokens.softhsm
CHECK_PORTABILITY_SKIP+=	tests/pkcs11-uri-without-token.softhsm

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
