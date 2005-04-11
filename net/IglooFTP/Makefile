# $NetBSD: Makefile,v 1.10 2005/04/11 21:46:44 tv Exp $

DISTNAME=	IglooFTP-0.6.1
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/network/file-transfer/} \
		ftp://littleigloo.org/pub/iglooftp/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.littleigloo.org/iglooftp.php3
COMMENT=	Easy to use FTP client for X Window System

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_X11=	yes

post-extract:
	${RM} ${WRKSRC}/../share/docs/LICENSE~

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
