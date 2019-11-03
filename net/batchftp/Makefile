# $NetBSD: Makefile,v 1.18 2019/11/03 11:45:30 rillig Exp $

DISTNAME=	batchftp102
PKGNAME=	batchftp-1.02
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/network/batchftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Automatically download files via the FTP protocol

WRKSRC=		${WRKDIR}

CPPFLAGS.Interix+=	-Dsetpgrp=setpgid
MAKE_ENV+=		BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}

INSTALLATION_DIRS=	bin share/doc/batchftp

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
