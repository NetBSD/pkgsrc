# $NetBSD: Makefile,v 1.22 2001/02/17 17:49:45 wiz Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/27 13:06:01 ache Exp
#

DISTNAME=	gnupg-1.0.4
PKGNAME=	${DISTNAME}nb3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/pub/gcrypt/gnupg/
# don't remove this -- we may add idea.c to it below
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

PATCHFILES=	gnupg-1.0.4.security-patch1.diff
PATCH_SITES=	ftp://ftp.gnupg.org/pub/gcrypt/gnupg/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Privacy Guard, a public-Key encryption and digital signature utility

BUILD_DEPENDS+=	msgfmt:../../devel/gettext

CRYPTO=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBINTL=	yes

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_IDEA

.if defined(USE_IDEA) && ${USE_IDEA} == YES
# use of IDEA as crypto function
LICENCE=        fee-based-commercial-use
MASTER_SITES+=	ftp://ftp.gnupg.org/pub/gcrypt/contrib/
DISTFILES+=	idea.c
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
PLIST_SUBST+=	IDEA=""

post-extract:
		${CP} ${_DISTDIR}/idea.c ${WRKSRC}

post-build:
		cd ${WRKSRC} && 				\
		${CC} -shared -Wl,-Bshareable -fPIC -o idea idea.c

post-install:
		${INSTALL_PROGRAM} ${WRKSRC}/idea ${PREFIX}/lib/gnupg
.else
PLIST_SUBST+=	IDEA="@comment "
.endif

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-1.1.3:../../devel/zlib
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.include "../../mk/bsd.pkg.mk"
