# $NetBSD: Makefile,v 1.13 2000/08/18 22:46:47 hubertf Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/27 13:06:01 ache Exp
#

DISTNAME=	gnupg-1.0.2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/pub/gcrypt/gnupg/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnupg.org/

DEPENDS+=	gettext>=0.10.35nb1:../../devel/gettext

USE_GMAKE=	yes

GNU_CONFIGURE=	yes

RESTRICTED=	"Cryptographic software"
NO_SRC_ON_FTP=	${RESTRICTED}
MIRROR_DISTFILE=no

.include "../../mk/bsd.prefs.mk"

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-1.1.3:../../devel/zlib
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.include "../../mk/bsd.pkg.mk"
