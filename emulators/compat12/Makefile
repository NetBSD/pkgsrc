# $NetBSD: Makefile,v 1.7 1998/07/15 12:01:42 agc Exp $
#

DISTNAME=	compat12
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	_${ARCH}.tgz

MAINTAINER=	tv@netbsd.org

ONLY_FOR_ARCHS=	amiga atari hp300 i386 mac68k mvme68k pc532 sparc sun3

MIRROR_DISTFILE= no
HAS_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/usr/lib
PLIST_SRC=	${WRKSRC}/.PLIST

post-extract:
	@${INSTALL} -c -m 755 ${FILESDIR}/configure ${WRKSRC}

.include "../../mk/bsd.pkg.mk"

# for sun3x in 1.3.x, get sun3 package
.if (${ARCH} == "sun3x")
ARCH=		sun3
.endif
