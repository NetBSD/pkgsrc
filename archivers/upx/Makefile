# $NetBSD: Makefile,v 1.16 2008/11/18 21:07:30 rillig Exp $

DISTNAME=	upx-1.25-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	misc archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=upx/}

MAINTAINER=	fab@gnux.info
HOMEPAGE=	http://upx.sourceforge.net/
COMMENT=	Ultimate packer for executables

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	gmake perl
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin

BUILDLINK_TRANSFORM=	rm:-mcpu=i686

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} PREFIX=${PREFIX} target=netbsd	\
			UCLDIR=${PREFIX} LDLIBDIRS=-L${PREFIX}/lib
	cd ${WRKSRC}/doc && ${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/upx ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/upx/
	${INSTALL_DATA} ${WRKSRC}/doc/upx.doc \
		${DESTDIR}${PREFIX}/share/doc/upx
	${INSTALL_DATA} ${WRKSRC}/doc/upx.html \
		${DESTDIR}${PREFIX}/share/doc/upx

.include "../../devel/ucl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
