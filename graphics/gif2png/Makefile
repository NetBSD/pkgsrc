# $NetBSD: Makefile,v 1.19 2002/03/13 17:37:07 fredb Exp $

DISTNAME=	gif2png-2.4.2
PKGREVISION=	1
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.tuxedo.org/~esr/gif2png/ \
		${MASTER_SITE_SUNSITE:=apps/graphics/convert/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/gif2png/
COMMENT=	convert GIF files to PNG

USE_BUILDLINK_ONLY=YES
GNU_CONFIGURE=	YES

post-install:
	${SED} "s,/usr/bin/python,${PREFIX}/bin/python,"			\
	       ${PREFIX}/bin/web2png > ${PREFIX}/bin/web2png.done
	${MV} ${PREFIX}/bin/web2png.done ${PREFIX}/bin/web2png
	${CHMOD} +x ${PREFIX}/bin/web2png

.include "../../graphics/png/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
