# $NetBSD: Makefile,v 1.1.1.1 2000/08/17 16:56:18 itojun Exp $
#

DISTNAME=       vorbis_nightly_cvs-20000818
PKGNAME=	vorbis-20000818
CATEGORIES=	audio
MASTER_SITES=   ${MASTER_SITE_LOCAL}
# daily snapshot
#MASTER_SITES=	http://www.xiph.org/ogg/vorbis/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.vorbis.com/

WRKSRC=		${WRKDIR}/vorbis
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	LIBS="${LIBS} -lossaudio"

post-build:
	(cd ${WRKSRC}/vorbis-tools; ${MAKE})

do-install:
	(cd ${WRKSRC}/vorbis-tools; ${MAKE} ${INSTALL_TARGET})

.include "../../mk/bsd.pkg.mk"
