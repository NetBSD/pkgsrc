# $NetBSD: Makefile,v 1.1.1.1 2004/08/20 01:16:21 jschauma Exp $
# FreeBSD Id: ports/print/poster/Makefile,v 1.6 2004/02/06 13:12:14 trevor Exp

DISTNAME=	poster
PKGNAME=	poster-1.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ics.ele.tue.nl/pub/users/jos/poster/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://printing.kde.org/downloads/
COMMENT=	Resize a ps image to print on larger media and/or multiple sheets

ALL_TARGET=	poster
WRKSRC=		${WRKDIR}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
