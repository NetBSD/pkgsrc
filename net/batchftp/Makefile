# $NetBSD: Makefile,v 1.3 2001/02/17 18:18:34 wiz Exp $

DISTNAME=	batchftp102
PKGNAME=	batchftp-1.02
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/network/batchftp/

MAINTAINER=	packages@netbsd.org
COMMENT=	Automatically download files via the FTP protocol

WRKSRC=		${WRKDIR}

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	${MKDIR} ${PREFIX}/share/doc/batchftp

.include "../../mk/bsd.pkg.mk"
