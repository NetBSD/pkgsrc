# $NetBSD: Makefile,v 1.4 2003/07/19 08:54:24 wiz Exp $
#

DISTNAME=		mscompress-0.3
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/compress/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		ftp://ftp.penguin.cz/pub/users/mhi/mscompress/
COMMENT=		Microsoft "compress.exe/expand.exe" compatible (de)compressor

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mscompress ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/msexpand ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mscompress.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/msexpand.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
