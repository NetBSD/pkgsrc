# $NetBSD: Makefile,v 1.9 2004/07/07 14:37:49 minskim Exp $

DISTNAME=	batchftp102
PKGNAME=	batchftp-1.02
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/network/batchftp/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Automatically download files via the FTP protocol

WRKSRC=		${WRKDIR}

MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/batchftp

.include "../../mk/bsd.pkg.mk"
