# $NetBSD: Makefile,v 1.6 1998/05/08 21:33:21 tron Exp $
#

DISTNAME=	compat11
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	_${ARCH}.tgz

MAINTAINER=	tv@netbsd.org

DEPENDS+=	compat12:../../emulators/compat12

ONLY_FOR_ARCHS=	amiga atari hp300 i386 mac68k mvme68k pc532 sparc sun3

HAS_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/usr/lib
PLIST_SRC=	${WRKSRC}/.PLIST

pre-configure:
	@${INSTALL} -c -m 755 ${FILESDIR}/configure ${WRKSRC}

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"

# for sun3x in 1.3.x, get sun3 package
.if (${ARCH} == "sun3x")
ARCH=	sun3
.endif
