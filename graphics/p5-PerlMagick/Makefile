# $NetBSD: Makefile,v 1.1.1.1 2000/04/23 01:59:57 kim Exp $

DISTNAME=		ImageMagick-5.1.1
PKGNAME=		p5-PerlMagick-5.1.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.wizards.dupont.com/cristy/ImageMagick.html

DEPENDS+=		ImageMagick-5.1.1:../../${MAGICK}

MAGICK=			graphics/ImageMagick
MAGICKDIR=		${PKGSRCDIR}/${MAGICK}
PATCHDIR=		${MAGICKDIR}/patches
PATCH_SUM_FILE=		${MAGICKDIR}/files/patch-sum
MD5_FILE=		${MAGICKDIR}/files/md5

.if !(make(do-configure) || make(do-patch))
WRKSRC=			${WRKDIR}/${DISTNAME}/PerlMagick
.endif

#EXTRACT_AFTER_ARGS+=	${WRKSRC}

MIRROR_DISTFILE=	no
USE_LIBTOOL=		yes
USE_PERL5=		yes
GNU_CONFIGURE=		yes

PERL5_BIN=		${LOCALBASE}/bin/perl

# These need to coordinate with the ImageMagick package.
# Just leave out "--without-perl".

CONFIGURE_ARGS+=	--with-perl=${PERL5_BIN} \
			--without-dps --without-fpx \
			--without-hdf --without-jbig --without-ttf

post-configure:
	cd ${WRKSRC} && ${PERL5_BIN} Makefile.PL

.include "../../mk/bsd.pkg.mk"
