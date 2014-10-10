# $NetBSD: Makefile,v 1.2 2014/10/10 11:19:29 adam Exp $

DISTNAME=	musepack_src_r475
PKGNAME=	musepack-0rc475
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musepack.net/
COMMENT=	MPEG-Plus and MusePack decoder (V8)
LICENSE=	modified-bsd

USE_CMAKE=		yes

INSTALLATION_DIRS=	lib

post-install:
	rm -rf ${DESTDIR}${PREFIX}/include/mpc/.svn/
	${INSTALL_LIB} ${WRKSRC}/libmpcdec/libmpcdec.* ${DESTDIR}${PREFIX}/lib

.include "../../audio/libcuefile/buildlink3.mk"
.include "../../audio/libreplaygain/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
