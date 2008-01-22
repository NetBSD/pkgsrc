# $NetBSD: Makefile,v 1.12 2008/01/22 17:09:55 tnn Exp $
#

DISTNAME=	sgi-fonts-1.0-457.src
PKGNAME=	sgi-fonts-1.0.457
PKGREVISION=	3
CATEGORIES=	fonts
MASTER_SITES=	http://public.planetmirror.com/pub/suse/i386/8.2/suse/src/
EXTRACT_SUFX=	.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oss.sgi.com/projects/sgi_propack/
COMMENT=	Linux compatibility package for SGI fonts

BUILD_DEPENDS+=	rpm2pkg>=1.3:../../pkgtools/rpm2pkg

WRKSRC=		${WRKDIR}/sgi-fonts

USE_IMAKE=	YES
USE_TOOLS+=	bdftopcf bzcat gtar gzip
FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/misc/sgi
REQD_DIRS+=		${PREFIX}/lib/X11/fonts/misc/sgi

do-extract:
	${LOCALBASE}/sbin/rpm2pkg -d ${WRKDIR} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	cd ${WRKDIR} && bzcat sgi-fonts.tar.bz2 | ${GTAR} xf -

post-install:
	${RM} ${PREFIX}/lib/X11/fonts/misc/sgi/fonts.scale

.include "../../mk/bsd.pkg.mk"
