# $NetBSD: Makefile,v 1.12 2006/02/09 18:19:39 rillig Exp $

DISTNAME=	upx-1.25-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	misc archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=upx/}

MAINTAINER=	fab@gnux.info
HOMEPAGE=	http://upx.sourceforge.net/
COMMENT=	Ultimate packer for executables

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	gmake perl

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC:Q}/src && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} PREFIX=${PREFIX:Q} target=netbsd	\
			UCLDIR=${PREFIX:Q} LDLIBDIRS=-L${PREFIX:Q}/lib
	cd ${WRKSRC:Q}/doc && ${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/src/upx ${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/upx/
	${INSTALL_DATA} ${WRKSRC:Q}/doc/upx.doc ${PREFIX:Q}/share/doc/upx
	${INSTALL_DATA} ${WRKSRC:Q}/doc/upx.html ${PREFIX:Q}/share/doc/upx

.include "../../devel/ucl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
