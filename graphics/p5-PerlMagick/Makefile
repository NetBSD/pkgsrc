# $NetBSD: Makefile,v 1.3 2000/08/14 01:37:38 kim Exp $

DISTNAME=		ImageMagick-5.2.2
PKGNAME=		p5-PerlMagick-5.2.2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.wizards.dupont.com/cristy/ImageMagick.html

DEPENDS+=		ImageMagick-5.2.2:../../${MAGICK}

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
USE_PKGLIBTOOL=		yes
USE_PERL5=		yes
GNU_CONFIGURE=		yes

PERL5_BIN=		${LOCALBASE}/bin/perl

# These need to coordinate with the ImageMagick package.
# Just leave out "--without-perl".

CONFIGURE_ARGS+=	--with-perl=${PERL5_BIN} \
			--without-dps --without-fpx \
			--without-hdf --without-jbig --without-threads \
			--without-ttf --without-xml

post-configure:
	cd ${WRKSRC} && ${PERL5_BIN} Makefile.PL

.include "../../mk/bsd.pkg.mk"
