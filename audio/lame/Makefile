# $NetBSD: Makefile,v 1.6 1999/10/13 05:58:22 explorer Exp $
#

#
# This file is included from ../lame-gui/Makefile to get most of the things
# to match up.  It will define LAME_GUI before including.
#

DISTNAME=	lame-3.33beta
CATEGORIES=	audio
MASTER_SITES=	http://www.sulaco.org/mp3/download/beta/
DISTFILES=	lame3.33beta.tar.gz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.sulaco.org/mp3/

DEPENDS=	ncurses-4.2:../../devel/ncurses

CONFLICTS=	lame-*

.include "../../mk/bsd.prefs.mk"

.if defined(LAME_USE_GTK) && ${LAME_USE_GTK} != NO
DEPENDS+=	gtk+-1.2.4:../../x11/gtk
.endif

WRKSRC=		${WRKDIR}/lame3.33
USE_GMAKE=	yes
ALL_TARGET=	lame
MIRROR_DISTFILE=no
LICENSE=	fee-based-commercial-use

.if !make(makepatchsum)
PATCHDIR=       ${WRKDIR}/.patches
.endif

post-extract:
	@${MKDIR} ${PATCHDIR}
	@${CP} ${.CURDIR}/patches/patch-* ${PATCHDIR}/
.if defined(LAME_USE_GTK) && ${LAME_USE_GTK} == NO
	@${RM} -f ${PATCHDIR}/patch-gtk
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lame ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
