# $NetBSD: Makefile,v 1.20 2015/07/04 16:18:33 joerg Exp $
#

DISTNAME=	sgi-fonts-1.0-457.src
PKGNAME=	sgi-fonts-1.0.457
PKGREVISION=	4
CATEGORIES=	fonts
MASTER_SITES=	http://public.planetmirror.com/pub/suse/i386/8.2/suse/src/
EXTRACT_SUFX=	.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oss.sgi.com/projects/sgi_propack/
COMMENT=	Linux compatibility package for SGI fonts

WRKSRC=		${WRKDIR}/sgi-fonts
USE_LANGUAGES=	c

FONTS_DIRS.x11=	${PREFIX}/share/fonts/X11/misc/sgi

USE_IMAKE=	yes
USE_TOOLS+=	bdftopcf bzcat tar pax gzip

INSTALLATION_DIRS=	share/fonts/X11/misc/sgi

post-extract:
	cd ${WRKDIR} && bzcat sgi-fonts.tar.bz2 | tar xf -

do-install:
	cd ${WRKSRC} && pax -rw -pm *pcf.gz \
		${DESTDIR}${PREFIX}/share/fonts/X11/misc/sgi
	${INSTALL_DATA} ${WRKSRC}/Scr15.pcf \
		${DESTDIR}${PREFIX}/share/fonts/X11/misc/sgi

.include "../../mk/bsd.pkg.mk"
