# $NetBSD: Makefile,v 1.7 2001/02/04 00:34:13 tron Exp $

DISTNAME=		ImageMagick-5.2.8
PKGNAME=		p5-PerlMagick-5.2.8
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.simplesystems.org/ImageMagick/

DEPENDS+=		${DISTNAME}:../../${MAGICK}

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

MAGICK=			graphics/ImageMagick
MAGICKDIR=		${PKGSRCDIR}/${MAGICK}
FILESDIR=		${MAGICKDIR}/files
PATCHDIR=		${MAGICKDIR}/patches

.if !(make(do-configure) || make(do-patch))
WRKSRC=			${WRKDIR}/${DISTNAME}/PerlMagick
.endif

#EXTRACT_AFTER_ARGS+=	${WRKSRC}

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_PERL5=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Image/Magick/.packlist

GNU_CONFIGURE=		YES
USE_X11=		YES

# These need to coordinate with the ImageMagick package.
# Just leave out "--without-perl".

CONFIGURE_ARGS+=	--with-perl=${PERL5} \
			--without-dps --without-fpx \
			--without-hdf --without-jbig --without-threads \
			--without-ttf --without-xml

post-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
