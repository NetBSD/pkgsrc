# $NetBSD: Makefile,v 1.4 2020/01/26 17:30:44 rillig Exp $

DISTNAME=	musepack_src_r475
PKGNAME=	musepack-0rc475
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.musepack.net/
COMMENT=	MPEG-Plus and MusePack decoder (V8)
LICENSE=	modified-bsd

USE_CMAKE=		yes

post-install:
	rm -rf ${DESTDIR}${PREFIX}/include/mpc/.svn/

.include "../../audio/libcuefile/buildlink3.mk"
.include "../../audio/libreplaygain/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
