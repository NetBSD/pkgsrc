# $NetBSD: Makefile,v 1.25 2003/12/28 11:36:02 wiz Exp $

DISTNAME=	gif2png-2.5.0
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/gif2png/
COMMENT=	Convert GIF files to PNG

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

post-install:
	${SED} "s,/usr/bin/python,${PREFIX}/bin/python,"		\
	       ${PREFIX}/bin/web2png > ${PREFIX}/bin/web2png.done
	${MV} ${PREFIX}/bin/web2png.done ${PREFIX}/bin/web2png
	${CHMOD} +x ${PREFIX}/bin/web2png

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
