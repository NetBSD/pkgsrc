# $NetBSD: Makefile,v 1.16 2000/10/11 09:57:45 itojun Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/27 13:06:01 ache Exp
#

DISTNAME=	gnupg-1.0.3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/pub/gcrypt/gnupg/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnupg.org/

DEPENDS+=	gettext>=0.10.35nb1:../../devel/gettext

CRYPTO=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.prefs.mk"

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-1.1.3:../../devel/zlib
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.include "../../mk/bsd.pkg.mk"
