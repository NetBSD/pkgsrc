# $NetBSD: Makefile,v 1.32 2002/07/18 20:44:52 heinz Exp $
#

DISTNAME=	gnupg-1.0.7
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/pub/gcrypt/gnupg/
# don't remove this -- we may add idea.c to it below
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Privacy Guard, a public-Key encryption and digital signature utility

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK_ONLY=	yes

CRYPTO=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

INFO_FILES=	gpgv.info

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_IDEA

.if defined(USE_IDEA) && ${USE_IDEA} == YES
# use of IDEA as crypto function
LICENCE=        fee-based-commercial-use
MASTER_SITES+=	ftp://ftp.gnupg.org/pub/gcrypt/contrib/
DISTFILES+=	idea.c.20010605
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
PLIST_SUBST+=	IDEA=""

post-extract:
		${CP} ${_DISTDIR}/idea.c.20010605 ${WRKSRC}/idea.c

post-build:
		cd ${WRKSRC} && 				\
		${CC} ${CFLAGS} -shared -Wl,-Bshareable -fPIC -o idea idea.c

post-install:
		${INSTALL_PROGRAM} ${WRKSRC}/idea ${PREFIX}/lib/gnupg
.else
PLIST_SUBST+=	IDEA="@comment "
.endif

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
