# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:38 jlam Exp $

DISTNAME=	upx-1.25-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	misc archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=upx/}

MAINTAINER=	fab@gnux.info
HOMEPAGE=	http://upx.sourceforge.net/
COMMENT=	Ultimate packer for executables

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	gmake perl

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} PREFIX=${PREFIX} target=netbsd		\
			UCLDIR=${PREFIX} LDLIBDIRS=-L${PREFIX}/lib
	cd ${WRKSRC}/doc && ${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/upx ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/upx/
	${INSTALL_DATA} ${WRKSRC}/doc/upx.doc ${PREFIX}/share/doc/upx
	${INSTALL_DATA} ${WRKSRC}/doc/upx.html ${PREFIX}/share/doc/upx

.include "../../devel/ucl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
