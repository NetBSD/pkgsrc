# $NetBSD: Makefile,v 1.11 2012/10/03 18:28:22 asau Exp $
#

DISTNAME=		font-util-1.3.0
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Tools for truncating and subseting of ISO10646-1 BDF fonts

GNU_CONFIGURE=		yes

LDFLAGS.IRIX+=		-lgen	# for basename(3)

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../mk/bsd.pkg.mk"
