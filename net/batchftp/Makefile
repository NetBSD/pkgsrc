# $NetBSD: Makefile,v 1.15 2008/06/20 01:09:29 joerg Exp $

DISTNAME=	batchftp102
PKGNAME=	batchftp-1.02
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/network/batchftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Automatically download files via the FTP protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

CPPFLAGS.Interix+= -Dsetpgrp=setpgid
MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}

INSTALLATION_DIRS=	bin share/doc/batchftp

post-extract:
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
