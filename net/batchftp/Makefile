# $NetBSD: Makefile,v 1.2 1999/10/07 17:41:56 tron Exp $

DISTNAME=	batchftp102
PKGNAME=	batchftp-1.02
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/network/batchftp/

MAINTAINER=	packages@netbsd.org

WRKSRC=		${WRKDIR}

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	${MKDIR} ${PREFIX}/share/doc/batchftp

.include "../../mk/bsd.pkg.mk"
