# $NetBSD: Makefile,v 1.1.1.1 1999/05/30 21:34:38 tron Exp $

DISTNAME=	batchftp102
PKGNAME=	batchftp-1.02
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/network/batchftp/

MAINTAINER=	tron@netbsd.org

WRKSRC=		${WRKDIR}

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	${MKDIR} ${PREFIX}/share/doc/batchftp

.include "../../mk/bsd.pkg.mk"
