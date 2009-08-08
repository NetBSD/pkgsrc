# $NetBSD: Makefile,v 1.7 2009/08/08 23:19:48 wiz Exp $
#

DISTNAME=		font-util-1.0.2
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

.include "../../mk/bsd.pkg.mk"
