# $NetBSD: Makefile,v 1.9 2000/03/21 22:40:52 tron Exp $
#

DISTNAME=	gif2png-2.3.0
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.tuxedo.org/~esr/gif2png/ \
		${MASTER_SITE_SUNSITE:=apps/graphics/convert/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/gif2png/

DEPENDS+=	png>=1.0.6:../../graphics/png

GNU_CONFIGURE=	YES
MAKE_ENV+=	INCLUDES="-I${PREFIX}/include"

post-install:
	${SED} s:/usr/bin/python:${PREFIX}/bin/python: \
	       <${PREFIX}/bin/web2png >${PREFIX}/bin/web2png.new
	${MV} ${PREFIX}/bin/web2png.new ${PREFIX}/bin/web2png
	${CHMOD} +x ${PREFIX}/bin/web2png

.include "../../mk/bsd.pkg.mk"
