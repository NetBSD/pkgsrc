# $NetBSD: Makefile,v 1.3 2005/03/24 21:13:00 wiz Exp $

DISTNAME=	poster
PKGNAME=	poster-1.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ics.ele.tue.nl/pub/users/jos/poster/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://printing.kde.org/downloads/
COMMENT=	Resize a ps image to print on larger media and/or multiple sheets

BUILD_TARGET=	poster
WRKSRC=		${WRKDIR}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
