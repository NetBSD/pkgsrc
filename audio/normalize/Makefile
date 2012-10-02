# $NetBSD: Makefile,v 1.26 2012/10/02 23:48:02 asau Exp $

DISTNAME=	normalize-0.7.7
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://savannah.nongnu.org/download/normalize/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://normalize.nongnu.org/
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
LDFLAGS+=		${LINKER_RPATH_FLAG}${BUILDLINK_PREFIX.libaudiofile}/lib -laudiofile

# is a generated file which doesn't exist when REPLACE_PERL happens
#REPLACE_PERL=		src/normalize-mp3

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
