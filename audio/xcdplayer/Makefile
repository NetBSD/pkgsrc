# $NetBSD: Makefile,v 1.27 2012/10/02 23:48:13 asau Exp $

DISTNAME=	xcdplayer-2.2
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	CD player for X

ONLY_FOR_PLATFORM=	SunOS-*-* IRIX-*-* DragonFly-*-* FreeBSD-*-* NetBSD-*-* OpenBSD-*-*

USE_IMAKE=	yes

pre-configure:
	${CP} ${FILESDIR}/cdrom_freebsd.c ${WRKSRC}
	${CP} ${FILESDIR}/cdrom_freebsd.h ${WRKSRC}
	${CP} ${WRKSRC}/xcdplayer.1 ${WRKSRC}/xcdplayer.man

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
