# $NetBSD: Makefile,v 1.8 2004/01/20 12:22:18 agc Exp $

DISTNAME=	batchftp102
PKGNAME=	batchftp-1.02
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/network/batchftp/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Automatically download files via the FTP protocol

WRKSRC=		${WRKDIR}

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/batchftp

.include "../../mk/bsd.pkg.mk"
