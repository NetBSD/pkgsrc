# $NetBSD: Makefile,v 1.30 2001/12/19 14:40:59 wiz Exp $
#

DISTNAME=	TiMidity++-2.10.4
PKGNAME=	${DISTNAME:S/TiMidity++/timidity/}
CATEGORIES=     audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.goice.co.jp/member/mo/timidity/
COMMENT=	MIDI to WAV renderer and player

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-vt100 --enable-audio=sun --disable-debug \
		--enable-gtk
USE_CONFIG_WRAPPER=	yes

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
