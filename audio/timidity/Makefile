# $NetBSD: Makefile,v 1.29 2001/02/16 13:30:50 wiz Exp $
#

DISTNAME=	TiMidity++-2.10.2
PKGNAME=	${DISTNAME:S/TiMidity++/timidity/}
CATEGORIES=     audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.goice.co.jp/member/mo/timidity/
COMMENT=	MIDI to WAV renderer and player

DEPENDS+=	gtk+>=1.2.8:../../x11/gtk

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-vt100 --enable-audio=sun --disable-debug \
		--enable-gtk

.include "../../mk/bsd.pkg.mk"
