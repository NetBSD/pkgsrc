# $NetBSD: Makefile,v 1.18 2023/09/08 10:29:15 wiz Exp $

DISTNAME=		font-util-1.4.1
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Tools for truncating and subseting of ISO10646-1 BDF fonts

GNU_CONFIGURE=		yes

LDFLAGS.IRIX+=		-lgen	# for basename(3)

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../mk/bsd.pkg.mk"
