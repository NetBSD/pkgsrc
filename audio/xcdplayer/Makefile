# $NetBSD: Makefile,v 1.14 2005/03/24 21:12:51 wiz Exp $

DISTNAME=       xcdplayer-2.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		ftp://ftp.cdrom.com/pub/X11/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	CD player for X

USE_IMAKE=	yes

pre-configure:
	${CP} ${FILESDIR}/cdrom_freebsd.c ${WRKSRC}
	${CP} ${FILESDIR}/cdrom_freebsd.h ${WRKSRC}
	${CP} ${WRKSRC}/xcdplayer.1 ${WRKSRC}/xcdplayer.man

.include "../../mk/bsd.pkg.mk"
