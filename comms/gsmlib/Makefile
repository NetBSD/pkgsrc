# $NetBSD: Makefile,v 1.28 2020/05/20 06:09:04 rillig Exp $
#

DISTNAME=	gsmlib-1.10
PKGREVISION=	3
CATEGORIES=	comms devel
#MASTER_SITES=	http://www.pxh.de/fs/gsmlib/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.pxh.de/fs/gsmlib/
COMMENT=	Library to access GSM mobile phones through GSM modems or IrDA devices

USE_TOOLS+=		gmake msgfmt
USE_LANGUAGES=		c c++03
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

# gsm_util.cc: In function 'std::string gsmlib::gsmToLatin1(std::string)':
# gsm_util.cc:107:72: error: array subscript has type 'char' [-Werror=char-subscripts]
#      result[i] = (unsigned char)s[i] > 127 ? NOP : gsmToLatin1Table[s[i]];
#                                                                         ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
