# $NetBSD: Makefile,v 1.22 2004/01/22 08:02:16 grant Exp $
#

DISTNAME=	rrdtool-1.0.40
PKGREVISION=	1
CATEGORIES=	databases graphics net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/pub/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/
COMMENT=	Data analysis tool generating graphical representations

#needs FPC code not found in older versions of NetBSD
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-alpha NetBSD-1.5-alpha \
			NetBSD-1.5.*-alpha NetBSD-1.5[A-U]-alpha

USE_LIBTOOL=	# defined
USE_BUILDLINK2=	# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig
LTCONFIG_OVERRIDE+=	${WRKSRC}/contrib/php4/ltconfig
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	# defined

CONFIGURE_ARGS= --enable-shared
CONFIGURE_ENV=	PERL=${PERL5}

PERL5_CONFIGURE=	NO
PERL5_PACKLIST+= 	${PERL5_SITEARCH}/auto/RRDp/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/RRDs/.packlist

INSTALL_DIRS=	${WRKSRC} ${WRKSRC}/perl-piped ${WRKSRC}/perl-shared

MAKE_ENV+=	CGILIB_INC=${BUILDLINK_PREFIX.cgilib}/include
MAKE_ENV+=	CGILIB_LIB=${BUILDLINK_PREFIX.cgilib}/lib
MAKE_ENV+=	GD_INC=${BUILDLINK_PREFIX.gd}/include
MAKE_ENV+=	GD_LIB=${BUILDLINK_PREFIX.gd}/lib
MAKE_ENV+=	JPEG_INC=${BUILDLINK_PREFIX.jpeg}/include
MAKE_ENV+=	JPEG_LIB=${BUILDLINK_PREFIX.jpeg}/lib
MAKE_ENV+=	ZLIB_INC=${BUILDLINK_PREFIX.zlib}/include
MAKE_ENV+=	ZLIB_LIB=${BUILDLINK_PREFIX.zlib}/lib
MAKE_ENV+=	PNG_INC=${BUILDLINK_PREFIX.png}/include
MAKE_ENV+=	PNG_LIB=${BUILDLINK_PREFIX.png}/lib
MAKE_ENV+=	TTF_INC=${BUILDLINK_PREFIX.freetype}/include
MAKE_ENV+=	TTF_LIB=${BUILDLINK_PREFIX.freetype}/lib

MAKE_ENV+=	_RPATH=${_OPSYS_RPATH_NAME}

# remove this or else it is installed
post-extract:
	${RM} ${WRKSRC}/perl-shared/ntmake.pl

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/gd/buildlink2.mk"
.include "../../www/cgilib/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
