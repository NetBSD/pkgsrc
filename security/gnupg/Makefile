# $NetBSD: Makefile,v 1.6 2000/02/27 04:16:55 wiz Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/27 13:06:01 ache Exp
#

DISTNAME=	gnupg-1.0.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/pub/gcrypt/gnupg/

MAINTAINER=	packages@NetBSD.ORG
HOMEPAGE=	http://www.gnupg.org/

DEPENDS+=	gettext-0.10.*:../../devel/gettext

USE_GMAKE=	yes

GNU_CONFIGURE=	yes

RESTRICTED=	"Cryptographic software"
MIRROR_DISTFILE=no

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-1.1.3:../../devel/zlib
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.include "../../mk/bsd.pkg.mk"
