# $NetBSD: Makefile,v 1.13 2001/12/15 20:25:36 agc Exp $

DISTNAME=		ImageMagick-5.3.9
PKGNAME=		p5-PerlMagick-5.3.9
SVR4_PKGNAME=		p5pma
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.simplesystems.org/ImageMagick/
COMMENT=		Object-oriented Perl interface to ImageMagick

DEPENDS+=		${DISTNAME}:../../${MAGICK}

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

MAGICK=			graphics/ImageMagick
MAGICKDIR=		${_PKGSRCDIR}/${MAGICK}
DISTINFO_FILE=		${MAGICKDIR}/distinfo
FILESDIR=		${MAGICKDIR}/files
PATCHDIR=		${MAGICKDIR}/patches

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
	cd ${WRKSRC}/PerlMagick && ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

do-build:
	@cd ${WRKSRC}/PerlMagick && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	@cd ${WRKSRC}/PerlMagick && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"
