# $NetBSD: Makefile,v 1.1.1.1 2004/12/28 00:01:07 xtraeme Exp $

DISTNAME=	xenvstat-20041127
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	X11-based display environmental sensor readings

ONLY_FOR_PLATFORM=	NetBSD-*-*

NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
USE_X11=	yes
USE_BUILDLINK3=	yes

LIBS=		-lXmu -lXext -lXt -lX11 -lm

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/xenvstat \
		${WRKSRC}/xenvstat.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xenvstat ${PREFIX}/bin/xenvstat
	${INSTALL_DATA} ${WRKSRC}/Xenvstat ${PREFIX}/lib/X11/app-defaults

.include "../../mk/bsd.pkg.mk"
