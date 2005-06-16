# $NetBSD: Makefile,v 1.14 2005/06/16 06:57:56 jlam Exp $

DISTNAME=	xevilsrc2.02r2
PKGNAME=	xevil-2.02
CATEGORIES=	games x11
MASTER_SITES=	http://www.xevil.com/download/stable/
EXTRACT_SUFX=	.zip

MAINTAINER=	snj@pobox.com
HOMEPAGE=	http://www.xevil.com/
COMMENT=	Side scrolling, bloody action game

MAKEFILE=	makefile

BUILD_TARGET=	pkgsrc
WRKSRC=		${WRKDIR}

MAKE_ENV+=	HOSTTYPE="pkgsrc"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x11/PKGSRC/xevil ${PREFIX}/bin/xevil
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xevil
	${INSTALL_DATA} ${WRKSRC}/instructions/* ${PREFIX}/share/doc/xevil

SUBST_CLASSES+=		uname
SUBST_STAGE.uname=	pre-configure
SUBST_FILES.uname=	cmn/utils.cpp
SUBST_SED.uname=	-e 's,@UNAME@,${UNAME},g'

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
