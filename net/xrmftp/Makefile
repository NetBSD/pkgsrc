# $NetBSD: Makefile,v 1.1.1.1 2002/04/21 11:07:04 rh Exp $

DISTNAME=	xrmftp-1.2.4
CATEGORIES=	net
MASTER_SITES=	http://www.mat.uni.torun.pl/~rafmet/xrmftp/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.mat.uni.torun.pl/~rafmet/xrmftp/
COMMENT=	FTP client for X Window System

USE_X11BASE=	yes
WRKSRC=		${WRKDIR}/xrmftp-1.2.4.src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrmftp ${PREFIX}/bin

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/xforms/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
