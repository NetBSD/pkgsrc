# $NetBSD: Makefile,v 1.21 2008/06/20 01:09:07 joerg Exp $

DISTNAME=	normalize-0.7.7
CATEGORIES=	audio
MASTER_SITES=	http://savannah.nongnu.org/download/normalize/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://normalize.nongnu.org/
COMMENT=	Audio file volume normalizer (wav,mp3,ogg)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-audiofile
CONFIGURE_ARGS+=	--with-mad

REPLACE_PERL=		src/normalize-mp3

.include "options.mk"

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
