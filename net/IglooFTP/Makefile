# $NetBSD: Makefile,v 1.1.1.1 2002/07/11 21:40:41 agc Exp $

DISTNAME=	IglooFTP-0.6.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/network/file-transfer/} \
		ftp://littleigloo.org/pub/iglooftp/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.littleigloo.org/iglooftp.php3
COMMENT=	Easy to use FTP client for X Window System

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_X11BASE=	yes

USE_CONFIG_WRAPPER=	yes

post-extract:
	${RM} ${WRKSRC}/../share/docs/LICENSE~

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
