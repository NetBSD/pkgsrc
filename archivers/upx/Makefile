# $NetBSD: Makefile,v 1.4 2004/03/30 06:44:53 uebayasi Exp $

DISTNAME=	upx-1.24-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	misc archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=upx/}

MAINTAINER=	fab@gnux.info
HOMEPAGE=	http://upx.sourceforge.net/
COMMENT=	Ultimate packer for executables

DEPENDS+=	ucl>=1.01:../../devel/ucl

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_GNU_TOOLS+=	make
USE_PERL5=	build

do-build:
	cd ${WRKSRC}/src && ${GMAKE} PREFIX=${PREFIX} target=netbsd
	cd ${WRKSRC}/doc && ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/upx ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/upx/
	${INSTALL_DATA} ${WRKSRC}/doc/upx.doc ${PREFIX}/share/doc/upx
	${INSTALL_DATA} ${WRKSRC}/doc/upx.html ${PREFIX}/share/doc/upx

.include "../../mk/bsd.pkg.mk"
