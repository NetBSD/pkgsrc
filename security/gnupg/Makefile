# $NetBSD: Makefile,v 1.10 2000/07/16 17:10:24 mason Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/27 13:06:01 ache Exp
#

DISTNAME=	gnupg-1.0.2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/pub/gcrypt/gnupg/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} gnupg-1.0.2.tar.gz

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnupg.org/

DEPENDS+=	gettext-0.10.*:../../devel/gettext

USE_GMAKE=	yes

GNU_CONFIGURE=	yes

RESTRICTED=	"Cryptographic software"
MIRROR_DISTFILE=no

.include "../../mk/bsd.prefs.mk"

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-1.1.3:../../devel/zlib
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

pre-configure:
	${GUNZIP_CMD} -c ${DISTDIR}/gnupg-1.0.2.tar.gz > ${WRKSRC}/doc/gpg.1

.include "../../mk/bsd.pkg.mk"
