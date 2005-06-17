# $NetBSD: Makefile,v 1.4 2005/06/17 03:50:30 jlam Exp $

DISTNAME=	poster
PKGNAME=	poster-1.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ics.ele.tue.nl/pub/users/jos/poster/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://printing.kde.org/downloads/
COMMENT=	Resize a ps image to print on larger media and/or multiple sheets

BUILD_TARGET=	poster
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin man/man1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
