#
# $NetBSD: Makefile,v 1.1 2002/11/07 08:06:36 sjg Exp $
#

PKGNAME=	urwfonts
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.gimp.org/
DISTNAME=	urw-fonts

MAINTAINER=	packages@netbsd.org
COMMENT=	Another font package for X

NO_PATCH=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined
WRKSRC=		${WRKDIR}
USE_X11BASE=	yes

X11FONTS=${PREFIX}/lib/X11/fonts

do-install:
	[ -d ${X11FONTS} ] || mkdir -p ${X11FONTS}
	cd ${WRKDIR} && tar -cf - URW | (cd ${X11FONTS} && tar -xf -)

.include "../../mk/bsd.pkg.mk"
