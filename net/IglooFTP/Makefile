# $NetBSD: Makefile,v 1.3 2003/03/29 12:41:53 jmmv Exp $

DISTNAME=	IglooFTP-0.6.1
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/network/file-transfer/} \
		ftp://littleigloo.org/pub/iglooftp/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.littleigloo.org/iglooftp.php3
COMMENT=	Easy to use FTP client for X Window System

USE_BUILDLINK2=	yes
USE_X11BASE=	yes

post-extract:
	${RM} ${WRKSRC}/../share/docs/LICENSE~

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
