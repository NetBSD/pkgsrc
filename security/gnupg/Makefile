# $NetBSD: Makefile,v 1.3 1999/04/09 09:39:20 agc Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/27 13:06:01 ache Exp
#

DISTNAME=	gnupg-0.9.5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/pub/gcrypt/

MAINTAINER=	packages@NetBSD.ORG
HOMEPAGE=	http://www.gnupg.org

GNU_CONFIGURE=  yes
RESTRICTED=	"Cryptographic software"
MIRROR_DISTFILE=no

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-1.1.3:../../devel/zlib
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.include "../../mk/bsd.pkg.mk"
