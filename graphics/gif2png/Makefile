# $NetBSD: Makefile,v 1.16 2001/05/22 09:32:20 wiz Exp $

DISTNAME=	gif2png-2.4.2
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.tuxedo.org/~esr/gif2png/ \
		${MASTER_SITE_SUNSITE:=apps/graphics/convert/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/gif2png/
COMMENT=	convert GIF files to PNG

DEPENDS+=	png>=1.0.11:../../graphics/png

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include

post-install:
	${SED} s:/usr/bin/python:${PREFIX}/bin/python: \
	       ${PREFIX}/bin/web2png > ${PREFIX}/bin/web2png.new
	${MV} ${PREFIX}/bin/web2png.new ${PREFIX}/bin/web2png
	${CHMOD} +x ${PREFIX}/bin/web2png

.include "../../mk/bsd.pkg.mk"
