# New ports collection makefile for:    compat12
# Version required:	1.2
# Date created:         17 Mar 1998
# Whom:                 tv@netbsd.org
#
# $NetBSD: Makefile,v 1.3 1998/03/26 17:35:39 tv Exp $
#

DISTNAME=	compat12
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	_${ARCH}.tgz

MAINTAINER=	tv@netbsd.org

HAS_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/usr/lib
PLIST_SRC=	${WRKSRC}/.PLIST

pre-fetch:
	@case ${ARCH} in \
		amiga|atari|hp300|i386|mac68k|mvme68k|pc532|sparc|sun3) ;; \
		*) ${ECHO_MSG} "This package cannot be built on ${ARCH}."; exit 1;; \
	esac

pre-configure:
	@${INSTALL} -c -m 755 ${FILESDIR}/configure ${WRKSRC}

post-install:
	${LDCONFIG} || ${TRUE}

.include <bsd.port.mk>

# for sun3x in 1.3.x, get sun3 package
.if (${ARCH} == "sun3x")
ARCH=		sun3
.endif
