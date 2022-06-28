# $NetBSD: Makefile,v 1.39 2022/06/28 11:30:55 wiz Exp $

DISTNAME=	normalize-0.7.7
PKGREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	http://savannah.nongnu.org/download/normalize/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://normalize.nongnu.org/
COMMENT=	Audio file volume normalizer (wav,mp3,ogg)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		perl
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-audiofile
CONFIGURE_ARGS+=	--with-audiofile-prefix=${BUILDLINK_PREFIX.libaudiofile}
CONFIGURE_ARGS+=	--disable-audiofiletest
CONFIGURE_ARGS+=	--with-mad
CPPFLAGS+=		-I${BUILDLINK_PREFIX.libaudiofile}/include
LDFLAGS+=		-L${BUILDLINK_PREFIX.libaudiofile}/lib
LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libaudiofile}/lib -laudiofile

# Hardcodes _POSIX_C_SOURCE=2 everywhere
CFLAGS.SunOS+=	-std=gnu89

# is a generated file which doesn't exist when REPLACE_PERL happens
#REPLACE_PERL=		src/normalize-mp3

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
