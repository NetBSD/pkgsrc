# $NetBSD: Makefile,v 1.16 2012/10/23 17:18:11 asau Exp $

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

INSTALLATION_DIRS=	bin share/doc/batchftp

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
