# $NetBSD: Makefile,v 1.4 1999/09/30 16:41:05 explorer Exp $
#

#
# This file is included from ../lame-gui/Makefile to get most of the things
# to match up.  It will define LAME_GUI before including.
#

.ifndef LAME_GUI
DISTNAME=	lame-3.31beta
.else
DISTNAME=	lame-gui-3.31beta
.endif
CATEGORIES=	audio
MASTER_SITES=	http://www.sulaco.org/mp3/download/beta/
DISTFILES=	lame3.31beta.tar.gz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.sulaco.org/mp3/

DEPENDS=	ncurses-4.2:../../devel/ncurses

.ifndef LAME_GUI
CONFLICTS=	lame-gui-*
.else
DEPENDS+=	gtk+-1.2.4:../../x11/gtk
CONFLICTS=	lame-[0-9]*
.endif

WRKSRC=		${WRKDIR}/lame3.31
USE_GMAKE=	yes
ALL_TARGET=	lame
MIRROR_DISTFILE=no
LICENSE=	fee-based-commercial-use

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lame ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
