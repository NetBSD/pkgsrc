# $NetBSD: Makefile,v 1.3 2002/12/28 21:22:55 jschauma Exp $

DISTNAME=	xrmftp-1.2.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.mat.uni.torun.pl/~rafmet/xrmftp/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.mat.uni.torun.pl/~rafmet/xrmftp/
COMMENT=	FTP client for X Window System

USE_BUILDLINK2=	yes
USE_X11BASE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}.src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrmftp ${PREFIX}/bin

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xforms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
