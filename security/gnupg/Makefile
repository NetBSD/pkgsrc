# $NetBSD: Makefile,v 1.25 2001/05/14 13:40:04 wiz Exp $
#

DISTNAME=	gnupg-1.0.5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/pub/gcrypt/gnupg/
# don't remove this -- we may add idea.c to it below
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Privacy Guard, a public-Key encryption and digital signature utility

BUILD_USES_MSGFMT=	yes

CRYPTO=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBINTL=	yes

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

INFO_FILES=	gpg.info gpgv.info

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
		${CC} ${CFLAGS} -shared -Wl,-Bshareable -fPIC -o idea idea.c

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
