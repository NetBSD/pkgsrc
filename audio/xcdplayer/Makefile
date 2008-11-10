# $NetBSD: Makefile,v 1.23 2008/11/10 17:21:33 wiz Exp $

DISTNAME=	xcdplayer-2.2
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	CD player for X

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	Interix-*-*

USE_IMAKE=	yes

pre-configure:
	${CP} ${FILESDIR}/cdrom_freebsd.c ${WRKSRC}
	${CP} ${FILESDIR}/cdrom_freebsd.h ${WRKSRC}
	${CP} ${WRKSRC}/xcdplayer.1 ${WRKSRC}/xcdplayer.man

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
