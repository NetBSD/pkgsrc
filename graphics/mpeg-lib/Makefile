# New ports collection makefile for:	mpeg
# Version required:			1.2.1
# Date created:				07 December 1997
# Whom:					tron@lyssa.owl.de
#
# $NetBSD: Makefile,v 1.3 1998/01/29 16:56:20 tron Exp $

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
	${LDCONFIG} -m ${PREFIX}/lib || /usr/bin/true

.include <bsd.port.mk>
