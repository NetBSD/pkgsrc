# New ports collection makefile for:    compat11
# Version required:	1.1
# Date created:         17 Mar 1998
# Whom:                 tv@netbsd.org
#
# $NetBSD: Makefile,v 1.1.1.1 1998/03/17 21:31:39 tv Exp $
#

DISTNAME=	compat11
EXTRACT_SUFX=	_${ARCH}.tgz
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
ONLY_FOR_ARCHS=	amiga atari hp300 i386 mac68k mvme68k pc532 sparc sun3

MAINTAINER=	tv@netbsd.org

LIB_DEPENDS=	edit.0.:${PORTSDIR}/emulators/compat12 \
		g++.3.:${PORTSDIR}/emulators/compat12 \
		util.3.:${PORTSDIR}/emulators/compat12
HAS_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/usr/lib
PLIST_SRC=	${WRKSRC}/.PLIST

pre-configure:
	@${INSTALL} -c -m 755 ${FILESDIR}/configure ${WRKSRC}

post-install:
	${LDCONFIG} || ${TRUE}

.include <bsd.port.mk>

# for sun3x in 1.3.x, get sun3 package
.if (${ARCH} == "sun3x")
ARCH=	sun3
.endif
