# $NetBSD: Makefile,v 1.13 2003/07/17 21:23:47 grant Exp $
# FreeBSD Id: Makefile,v 1.8 1997/04/01 23:08:24 swallace Exp
#

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
