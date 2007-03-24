# $NetBSD: Makefile,v 1.1.1.1 2007/03/24 22:42:50 joerg Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-fonts-1.0
CATEGORIES=	meta-pkgs fonts x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/fonts/
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg font meta-package

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	font-adobe-100dpi-[0-9]*:../../fonts/font-adobe-100dpi
DEPENDS+=	font-adobe-75dpi-[0-9]*:../../fonts/font-adobe-75dpi
DEPENDS+=	font-adobe-utopia-100dpi-[0-9]*:../../fonts/font-adobe-utopia-100dpi
DEPENDS+=	font-adobe-utopia-75dpi-[0-9]*:../../fonts/font-adobe-utopia-75dpi
DEPENDS+=	font-adobe-utopia-type1-[0-9]*:../../fonts/font-adobe-utopia-type1
DEPENDS+=	font-alias-[0-9]*:../../fonts/font-alias
DEPENDS+=	font-bh-100dpi-[0-9]*:../../fonts/font-bh-100dpi
DEPENDS+=	font-bh-75dpi-[0-9]*:../../fonts/font-bh-75dpi
DEPENDS+=	font-bh-lucidatypewriter-100dpi-[0-9]*:../../fonts/font-bh-lucidatypewriter-100dpi
DEPENDS+=	font-bh-lucidatypewriter-75dpi-[0-9]*:../../fonts/font-bh-lucidatypewriter-75dpi
DEPENDS+=	font-bh-ttf-[0-9]*:../../fonts/font-bh-ttf
DEPENDS+=	font-bh-type1-[0-9]*:../../fonts/font-bh-type1
DEPENDS+=	font-bitstream-100dpi-[0-9]*:../../fonts/font-bitstream-100dpi
DEPENDS+=	font-bitstream-75dpi-[0-9]*:../../fonts/font-bitstream-75dpi
DEPENDS+=	font-bitstream-type1-[0-9]*:../../fonts/font-bitstream-type1
DEPENDS+=	font-cursor-misc-[0-9]*:../../fonts/font-cursor-misc
DEPENDS+=	font-daewoo-misc-[0-9]*:../../fonts/font-daewoo-misc
DEPENDS+=	font-dec-misc-[0-9]*:../../fonts/font-dec-misc
DEPENDS+=	font-ibm-type1-[0-9]*:../../fonts/font-ibm-type1
DEPENDS+=	font-isas-misc-[0-9]*:../../fonts/font-isas-misc
DEPENDS+=	font-jis-misc-[0-9]*:../../fonts/font-jis-misc
DEPENDS+=	font-misc-misc-[0-9]*:../../fonts/font-misc-misc
DEPENDS+=	font-mutt-misc-[0-9]*:../../fonts/font-mutt-misc
DEPENDS+=	vera-ttf-[0-9]*:../../fonts/vera-ttf

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_CONFIGURE=		yes

do-install:

.include "../../mk/bsd.pkg.mk"
