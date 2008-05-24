# $NetBSD: Makefile,v 1.6 2008/05/24 21:45:21 tnn Exp $
#

DISTNAME=		font-util-1.0.1
PKGREVISION=		1
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Tools for truncating and subseting of ISO10646-1 BDF fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

LDFLAGS.IRIX+=		-lgen	# for basename(3)

post-extract:
	${CP} ${FILESDIR}/bdftruncate.c ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
