# $NetBSD: Makefile,v 1.12 2015/03/15 20:41:17 wiz Exp $

DISTNAME=		font-util-1.3.1
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
