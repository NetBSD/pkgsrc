# $NetBSD: Makefile,v 1.5 2005/02/10 15:51:38 ben Exp $

DISTNAME=	upx-1.25-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	misc archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=upx/}

MAINTAINER=	fab@gnux.info
HOMEPAGE=	http://upx.sourceforge.net/
COMMENT=	Ultimate packer for executables

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_GNU_TOOLS+=	make
USE_PERL5=	build
USE_BUILDLINK3=	yes

do-build:
	cd ${WRKSRC}/src && ${MAKE_PROGRAM} PREFIX=${PREFIX} target=netbsd UCLDIR=${PREFIX} LDLIBDIRS=-L${PREFIX}/lib
	cd ${WRKSRC}/doc && ${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/upx ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/upx/
	${INSTALL_DATA} ${WRKSRC}/doc/upx.doc ${PREFIX}/share/doc/upx
	${INSTALL_DATA} ${WRKSRC}/doc/upx.html ${PREFIX}/share/doc/upx

.include "../../devel/ucl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
