# $NetBSD: Makefile,v 1.23 2003/07/21 16:51:42 martti Exp $

DISTNAME=	gif2png-2.4.6
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.tuxedo.org/~esr/gif2png/ \
		${MASTER_SITE_SUNSITE:=apps/graphics/convert/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tuxedo.org/~esr/gif2png/
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
