# $NetBSD: Makefile,v 1.28 2004/11/30 16:04:45 adam Exp $

DISTNAME=	gif2png-2.5.1
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/gif2png/
COMMENT=	Convert GIF files to PNG

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

post-install:
	${SED} "s,/usr/bin/python,${PREFIX}/bin/python,"		\
	       ${PREFIX}/bin/web2png > ${PREFIX}/bin/web2png.done
	${MV} ${PREFIX}/bin/web2png.done ${PREFIX}/bin/web2png
	${CHMOD} +x ${PREFIX}/bin/web2png

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
