# $NetBSD: Makefile,v 1.14 2006/03/04 21:30:16 jlam Exp $

DISTNAME=	batchftp102
PKGNAME=	batchftp-1.02
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/network/batchftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Automatically download files via the FTP protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}

CPPFLAGS.Interix+= -Dsetpgrp=setpgid
MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}

INSTALLATION_DIRS=	bin

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/batchftp

.include "../../mk/bsd.pkg.mk"
