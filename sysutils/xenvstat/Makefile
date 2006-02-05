# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:57 joerg Exp $

DISTNAME=	xenvstat-20041127
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	X11-based display environmental sensor readings

ONLY_FOR_PLATFORM=	NetBSD-*-*

NO_CONFIGURE=	yes
NO_CHECKSUM=	yes

LIBS+=		-lXmu -lXext -lXt -lX11 -lm

INSTALLATION_DIRS=	bin lib/X11/app-defaults

.include "../../mk/x11.buildlink3.mk"

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/xenvstat \
		${WRKSRC}/xenvstat.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xenvstat ${PREFIX}/bin/xenvstat
	${INSTALL_DATA} ${WRKSRC}/Xenvstat ${PREFIX}/lib/X11/app-defaults

.include "../../mk/bsd.pkg.mk"
