# $NetBSD: Makefile,v 1.4 2007/08/05 19:20:19 joerg Exp $
#

DISTNAME=		font-util-1.0.1
PKGREVISION=		1
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Tools for truncating and subseting of ISO10646-1 BDF fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

post-extract:
	${CP} ${FILESDIR}/bdftruncate.c ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
