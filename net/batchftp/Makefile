# $NetBSD: Makefile,v 1.7 2003/07/17 22:51:00 grant Exp $

DISTNAME=	batchftp102
PKGNAME=	batchftp-1.02
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/network/batchftp/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Automatically download files via the FTP protocol

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/batchftp

.include "../../mk/bsd.pkg.mk"
