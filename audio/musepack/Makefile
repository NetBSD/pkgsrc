# $NetBSD: Makefile,v 1.8 2025/10/12 01:05:52 mrg Exp $

DISTNAME=	musepack_src_r475
PKGNAME=	musepack-0rc475
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.musepack.net/
COMMENT=	MPEG-Plus and MusePack decoder (V8)
LICENSE=	modified-bsd

CONFLICTS=	libmpcdec-[0-9]*

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

post-install:
	rm -rf ${DESTDIR}${PREFIX}/include/mpc/.svn/

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-14.*) || !empty(CC_VERSION:Mgcc-15.*)
CFLAGS+=	-Wno-incompatible-pointer-types
.endif

.include "../../devel/cmake/build.mk"
.include "../../audio/libcuefile/buildlink3.mk"
.include "../../audio/libreplaygain/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
