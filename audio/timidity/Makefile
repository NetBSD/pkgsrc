# $NetBSD: Makefile,v 1.28 2000/12/17 01:37:40 wiz Exp $
#

DISTNAME=	TiMidity++-2.10.2
PKGNAME=	${DISTNAME:S/TiMidity++/timidity/}
CATEGORIES=     audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.goice.co.jp/member/mo/timidity/

DEPENDS+=	gtk+>=1.2.8:../../x11/gtk

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-vt100 --enable-audio=sun --disable-debug \
		--enable-gtk

.include "../../mk/bsd.pkg.mk"
