# $NetBSD: Makefile,v 1.7 2025/08/12 09:17:05 adam Exp $

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

.include "../../devel/cmake/build.mk"
.include "../../audio/libcuefile/buildlink3.mk"
.include "../../audio/libreplaygain/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
