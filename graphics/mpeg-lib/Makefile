# $NetBSD: Makefile,v 1.6 1998/04/15 10:38:26 agc Exp $

DISTNAME=	mpeg_lib-1.2.1
PKGNAME=	mpeg-1.2.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mni.mcgill.ca/pub/mpeg/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/libs/ \
		ftp://ftp.gimp.org/pub/gimp/libs/

MAINTAINER=	tron@netbsd.org

HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/mpeg_lib

post-configure:
	ln -fs ${FILESDIR}/Makefile ${WRKSRC}
	ln -s ${FILESDIR}/shlib_version ${WRKSRC}

post-install:
	(cd ${WRKSRC};make PREFIX=${PREFIX} includes)
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
