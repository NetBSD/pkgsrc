# $NetBSD: Makefile,v 1.13 2009/12/17 17:21:18 abs Exp $
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

WRKSRC=		${WRKDIR}/sgi-fonts
PKG_DESTDIR_SUPPORT= user-destdir

USE_IMAKE=	YES
USE_TOOLS+=	bdftopcf bzcat gtar gzip rpm2pkg
FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/misc/sgi
REQD_DIRS+=		${PREFIX}/lib/X11/fonts/misc/sgi

do-extract:
	rpm2pkg -d ${WRKDIR} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	cd ${WRKDIR} && bzcat sgi-fonts.tar.bz2 | ${GTAR} xf -

post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/X11/fonts/misc/sgi/fonts.scale

.include "../../mk/bsd.pkg.mk"
