# $NetBSD: Makefile,v 1.16 2012/10/03 18:28:30 asau Exp $
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
USE_LANGUAGES=	# none

USE_X11BASE=	yes
FONTS_DIRS.x11=	${PREFIX}/lib/X11/fonts/misc/sgi

USE_IMAKE=	yes
USE_TOOLS+=	bdftopcf bzcat tar pax

INSTALLATION_DIRS=	lib/X11/fonts/misc/sgi

post-extract:
	cd ${WRKDIR} && bzcat sgi-fonts.tar.bz2 | tar xf -

do-install:
	cd ${WRKSRC} && pax -rw -pm *pcf.gz \
		${DESTDIR}${PREFIX}/lib/X11/fonts/misc/sgi
	${INSTALL_DATA} ${WRKSRC}/Scr15.pcf \
		${DESTDIR}${PREFIX}/lib/X11/fonts/misc/sgi

.include "../../mk/bsd.pkg.mk"
