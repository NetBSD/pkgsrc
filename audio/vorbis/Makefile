# $NetBSD: Makefile,v 1.5 2000/10/06 03:17:09 dmcmahill Exp $
#

DISTNAME=       vorbis_nightly_cvs-20000818
PKGNAME=	vorbis-20000818
CATEGORIES=	audio
# daily snapshot (vorbis-nightly-cvs.tgz) is copied into "LOCAL_PORTS"
# so that we can get a version of certain date
MASTER_SITES=   ${MASTER_SITE_LOCAL}
#MASTER_SITES=	http://www.xiph.org/ogg/vorbis/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.vorbis.com/

.if !exists(/usr/include/getopt.h)
DEPENDS+=	libgetopt-1.1:../../devel/libgetopt
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -lgetopt
.endif

WRKSRC=		${WRKDIR}/vorbis
GNU_CONFIGURE=	YES
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	LIBS="${LDFLAGS} ${LIBS} -lossaudio"

post-build:
	(cd ${WRKSRC}/vorbis-tools; ${MAKE})

do-install:
	(cd ${WRKSRC}/vorbis-tools; ${MAKE} ${INSTALL_TARGET})

.include "../../mk/bsd.pkg.mk"
