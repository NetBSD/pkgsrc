# $NetBSD: Makefile,v 1.29 2025/04/24 14:15:30 wiz Exp $

DISTNAME=	xrmftp-1.2.4
PKGREVISION=	12
CATEGORIES=	net
#MASTER_SITES=	http://www-users.mat.uni.torun.pl/~rafmet/xrmftp/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=	http://www-users.mat.uni.torun.pl/~rafmet/xrmftp/
COMMENT=	FTP client for X Window System

WRKSRC=		${WRKDIR}/${DISTNAME}.src

INSTALLATION_DIRS=	bin

LDFLAGS.SunOS+=	-lsocket -lnsl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrmftp ${DESTDIR}${PREFIX}/bin

.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
