# $NetBSD: Makefile,v 1.7 1998/07/10 17:56:30 tv Exp $

DISTNAME=	mpeg_lib-1.2.1
PKGNAME=	mpeg-1.2.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mni.mcgill.ca/pub/mpeg/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/libs/ \
		ftp://ftp.gimp.org/pub/gimp/libs/

MAINTAINER=	tron@netbsd.org

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/mpeg_lib

post-configure:
	ln -fs ${FILESDIR}/Makefile ${WRKSRC}
	ln -s ${FILESDIR}/shlib_version ${WRKSRC}

post-install:
	(cd ${WRKSRC};make PREFIX=${PREFIX} includes)
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
