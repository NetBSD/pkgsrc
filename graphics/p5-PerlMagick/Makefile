# $NetBSD: Makefile,v 1.6 2000/08/27 07:11:13 jlam Exp $

DISTNAME=		ImageMagick-5.2.2
PKGNAME=		p5-PerlMagick-5.2.2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.wizards.dupont.com/cristy/ImageMagick.html

DEPENDS+=		ImageMagick-5.2.2:../../${MAGICK}

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

MAGICK=			graphics/ImageMagick
MAGICKDIR=		${PKGSRCDIR}/${MAGICK}
PATCHDIR=		${MAGICKDIR}/patches
PATCH_SUM_FILE=		${MAGICKDIR}/files/patch-sum
MD5_FILE=		${MAGICKDIR}/files/md5

.if !(make(do-configure) || make(do-patch))
WRKSRC=			${WRKDIR}/${DISTNAME}/PerlMagick
.endif

#EXTRACT_AFTER_ARGS+=	${WRKSRC}

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Image/Magick/.packlist

GNU_CONFIGURE=		yes

# These need to coordinate with the ImageMagick package.
# Just leave out "--without-perl".

CONFIGURE_ARGS+=	--with-perl=${PERL5} \
			--without-dps --without-fpx \
			--without-hdf --without-jbig --without-threads \
			--without-ttf --without-xml

post-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
