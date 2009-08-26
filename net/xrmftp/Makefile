# $NetBSD: Makefile,v 1.15 2009/08/26 19:58:12 sno Exp $

DISTNAME=	xrmftp-1.2.4
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www-users.mat.uni.torun.pl/~rafmet/xrmftp/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www-users.mat.uni.torun.pl/~rafmet/xrmftp/
COMMENT=	FTP client for X Window System

WRKSRC=		${WRKDIR}/${DISTNAME}.src
USE_X11BASE=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrmftp ${PREFIX}/bin

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
